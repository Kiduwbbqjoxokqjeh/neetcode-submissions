class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(),m = abbr.size();
        int i=0,j=0;
        while(i<n and j<m)
        {
            if(isalpha(abbr[j]))
            {
                if(abbr[j] != word[i]) return false;
                i++;j++;
            }
            else
            {
                if(abbr[j] == '0') return false;
                int l=0;
                while(j<m and isdigit(abbr[j]))
                {
                    l = l*10 + (abbr[j] - '0');
                    j++;
                }
                i+=l;
            }
        }
        return i == n and j == m ;
    }
};