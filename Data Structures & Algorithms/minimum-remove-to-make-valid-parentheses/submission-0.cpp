class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();
        int bal=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') bal++;
            else if(s[i] == ')')
            {
                if(bal == 0) s[i] = '*';
                else bal--;
            }
        }
        bal=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ')') bal++;
            else if(s[i] == '(')
            {
                if(bal == 0) s[i] = '*';
                else bal--;
            }
        }
        string ans;
        for(int i=0;i<n;i++)
        {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
        
    }
};
