class Solution {
public:
    bool ispal(string &z)
    {
        int i=0,j=z.size()-1;
        while(i<j)
        {
            if(z[i++] != z[j--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string x = s.substr(0,i);
            string y = s.substr(i+1);
            string z = x+y;
            if(ispal(z)) return true;
        }
        return false;
    }
};