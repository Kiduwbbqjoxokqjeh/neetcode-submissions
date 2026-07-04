class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for(char c:s)
        {
            if(mp.count(c))
            {
                st.push(c);
            }
            else
            {
                if(st.empty() or mp[st.top()] != c) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
