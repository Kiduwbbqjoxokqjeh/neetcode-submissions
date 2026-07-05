class Solution {
public:
    string decodeString(string s) {
        stack<int> a;
        stack<string> b;
        int num=0;
        string curr;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(isdigit(ch)) num = num*10 + (ch-'0');
            else if(ch == '[')
            {
                a.push(num);b.push(curr);
                num=0;curr = "";
            }
            else if(ch == ']')
            {
                int k = a.top();a.pop();
                string prev = b.top();b.pop();
                while(k--)
                {
                    prev += curr;
                }
                curr = prev;
            }
            else curr += ch;
        }
        return curr;
    }
};