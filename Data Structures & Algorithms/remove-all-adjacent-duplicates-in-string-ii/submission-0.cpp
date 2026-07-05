class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() or st.top().first != s[i])
            {
                st.push({s[i],1});
            }
            else
            {
                st.top().second++;
                if(st.top().second == k)
                {
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty())
        {
            auto x = st.top();st.pop();
            while(x.second--)
            {
                ans += x.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};