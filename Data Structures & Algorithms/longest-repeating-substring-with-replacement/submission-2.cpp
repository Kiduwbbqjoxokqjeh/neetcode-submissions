class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        for(auto &x:s) st.insert(x);
        // b a c
        int ans=0;
        for(auto &ch:st)
        {
            int count=0,l=0;
            for(int r=0;r<s.size();r++)
            {
                if(s[r] == ch) count++;

                while((r-l+1) - count > k)
                {
                    if(s[l] == ch)
                    {
                        count--;
                    }
                    l++;
                }

                ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};
