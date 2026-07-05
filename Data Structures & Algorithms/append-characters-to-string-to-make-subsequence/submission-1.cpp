class Solution {
public:
    int appendCharacters(string s, string t) {

        int i=0,j=0;
        while(j<s.size() and i<t.size())
        {
            if(t[i] == s[j]) i++;
            j++;
        }
        int ans = t.size() - i; 
        return ans;
    }
};