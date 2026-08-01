class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0,j=0;
        while(i<word.size() and j<abbr.size())
        {
            if(isalpha(abbr[j]))
            {
                if(word[i] != abbr[j]) return false;
                i++;j++;
            }
            else
            {
                if(abbr[j] == '0') return false;
                int k=j;
                while(k<abbr.size() and isdigit(abbr[k])) k++;
                i += stoi(abbr.substr(j,k-j));
                j=k;
            }
        }
        return i==word.size() and j==abbr.size();
    }
};