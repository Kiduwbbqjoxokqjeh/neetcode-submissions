class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size(),bal=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') bal++;
            else if(s[i] == ')') 
            {
                if(bal>0) bal--;
                else s[i]  = '*';
            }
        }
        bal=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ')')bal++;
            else if(s[i] == '(')
            {
                if(bal>0) bal--;
                else s[i] = '*';
            }
        }
        string ans;
        for(auto &x:s)
        {
            if(x!='*') ans += x;
        }
        return ans;
    }
};
