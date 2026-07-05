class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int num=0;
        for(int i=0;i<=s.size();i++)
        {
            char ch = s[i];
            if(isdigit(ch))
            {
                num = num*10 + (ch-'0');
            }
            if(i == s.size() or (!isdigit(ch) and ch != ' '))
            {
                if(op == '+')
                {
                    st.push(num);
                }
                else if(op == '-')
                {
                    st.push(-num);
                }
                else if(op == '*')
                {
                    int x = st.top(); st.pop();
                    st.push(x*num);
                }
                else 
                {
                    int x = st.top();st.pop();
                    st.push(x/num);
                }

                if(i<s.size())
                {
                    op = ch;
                }
                num = 0;
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum += st.top();st.pop();
        }
        return sum;
    }
};