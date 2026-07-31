class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int bal=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(') bal++;
            else if(s[i] == ')')
            {
                if(bal>0) bal--;
                else s[i] = '*';
            }
        }
        bal=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == ')') bal++;
            else if(s[i] == '(')
            {
                if(bal>0) bal--;
                else s[i] = '*';
            }
        }
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};
