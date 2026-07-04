class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res=0;
        for(auto &x:operations)
        {
            if(x == "+")
            {
                int top = st.top(); st.pop();
                int newtop = top + st.top();
                st.push(top);
                st.push(newtop);
            }
            else if(x == "C")
            {
                if(!st.empty()) st.pop();
            }
            else if(x == "D")
            {
                st.push(2*st.top());
            }
            else 
            {
                st.push(stoi(x));
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum += st.top(); st.pop();
        }
        return sum;
    }
};