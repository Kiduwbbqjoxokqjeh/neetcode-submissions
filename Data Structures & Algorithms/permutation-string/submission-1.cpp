class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        for(auto &x:s1) mp1[x]++;
        int need = mp1.size();

        for(int i=0;i<s2.size();i++)
        {
            unordered_map<char,int> mp2;
            int curr=0;
            for(int j=i;j<s2.size();j++)
            {
                char ch = s2[j];
                mp2[ch]++;
                if(mp1[ch] < mp2[ch]) break;

                if(mp1[ch] == mp2[ch])
                {
                    curr++;
                }

                if(curr == need) return true;

            }
        }
        return false;
    }
};
