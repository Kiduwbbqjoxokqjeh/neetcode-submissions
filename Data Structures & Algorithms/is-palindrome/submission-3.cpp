class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto &ch:s)
        {
            if(isalnum(ch)) t += tolower(ch);
        }
        int i=0,j=t.size()-1;
        while(i<j)
        {
            if(t[i++] != t[j--])return false;
        }
        return true;
    }
};
