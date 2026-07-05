class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        stack<string> st;
        for(int i=0;i<=path.size();i++)
        {
            if(i == path.size() or path[i] == '/')
            {
                if(curr == "" or curr == "."){}
                else if(curr == "..") 
                {
                    if(!st.empty()) st.pop();
                }
                else st.push(curr);
                curr = "";
            }
            else curr += path[i];
        }
        if(st.empty()) return "/";
        vector<string> x;
        while(!st.empty())
        {
            x.push_back(st.top());st.pop();
        }
        reverse(x.begin(),x.end());
        string ans;
        for(auto &dir:x)
        {
            ans += "/" + dir;
        }
        return ans;
    }
};