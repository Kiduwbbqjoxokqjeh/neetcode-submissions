class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto &x:logs)
        {
            if(x == "../")
            {
                if(!st.empty()) st.pop();
            }
            else if(x != "./")
            {
                st.push(x);
            }
        }   
        return st.size();
    }
};