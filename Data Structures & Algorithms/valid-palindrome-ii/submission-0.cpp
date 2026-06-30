class Solution {
public:
    bool ispal(string &x)
    {
        int l=0,r=x.size()-1;
        while(l<r)
        {
            if(x[l++] != x[r--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(ispal(s)) return true;

        for(int i=0;i<s.size();i++)
        {
            string x = s.substr(0,i) + s.substr(i+1);
            if(ispal(x)) return true;
        }
        return false;   
    }
};