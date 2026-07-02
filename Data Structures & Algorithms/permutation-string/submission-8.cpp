class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        if(n>m) return false;
        unordered_map<char,int> mp1;
        for(auto &x:s1) mp1[x]++;
        int need = mp1.size();

        for(int i=0;i<=(m-n);i++)
        {
            unordered_map<char,int> mp2;
            int curr=0;
            for(int j=i;j<(i+n);j++)
            {
                char ch = s2[j];
                if(!mp1.count(ch)) break;
                mp2[ch]++;

                if(mp1[ch] < mp2[ch]) break;
                if(mp1[ch] == mp2[ch]) curr++;
                if(curr == need) return true;
            }
        }
        return false;
    }
};
