class Solution {
public:
    string decodeString(string s) {
        int num=0;
        string curr="";
        stack<int> number;
        stack<string> stringstack;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i] - '0');
            }
            else if(s[i] == '[')
            {
                number.push(num);
                stringstack.push(curr);
                num=0;
                curr = "";
            }
            else if(s[i] == ']')
            {
                int k = number.top();number.pop();
                string prev = stringstack.top();stringstack.pop();
                while(k--)
                {
                    prev += curr;
                }
                curr = prev;
            }
            else curr += s[i];
        }
        return curr;
    }
};