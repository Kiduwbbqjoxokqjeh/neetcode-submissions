class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        set<char> st(allowed.begin(),allowed.end());
        int ans=0;

        for(auto &word:words)
        {
            bool flag = true;
            for(auto &c: word)
            {
                if(st.count(c) == 0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans += 1;
        }

        return ans;
        
    }
};