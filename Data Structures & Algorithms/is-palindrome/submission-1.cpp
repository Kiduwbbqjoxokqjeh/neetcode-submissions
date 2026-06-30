class Solution {
public:
    bool isPalindrome(string s) {

        string x;
        for(auto &y:s)
        {
            if(isalnum(y)) x += tolower(y);
        }
        int n = x.size();
        // x = was it a car or a cat i saw
        for(int i=0;i<n/2;i++)
        {
            if(x[i] != x[n-1-i]) return false;
        }
        return true;
    }
};
