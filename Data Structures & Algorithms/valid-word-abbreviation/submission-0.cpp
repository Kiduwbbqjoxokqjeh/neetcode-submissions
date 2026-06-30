class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word == abbr) return true;
        int n = word.size(),m = abbr.size();
        int i=0,j=0;
        while(i<n and j<m)
        {
            if(abbr[j] == '0') return false;
            if(isalpha(abbr[j]))
            {
                if(abbr[j] == word[i])
                {
                    i++;j++;
                }
                else return false;
            }
            else
            {
                int len=0;
                while(j<m and isdigit(abbr[j]))
                {
                    len = len*10 + (abbr[j++] - '0');
                }
                i += len;
            }
        }
        return i == n and j == m;
    }
};