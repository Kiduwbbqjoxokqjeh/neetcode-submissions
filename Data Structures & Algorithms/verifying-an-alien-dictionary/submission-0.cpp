class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26);
        for(int i=0;i<26;i++)
        {
            pos[order[i] - 'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string a = words[i],b = words[i+1];
            int j=0;
            while(j<a.size() and j<b.size())
            {
                if(a[j] != b[j])
                {
                    int x = pos[a[j] - 'a'],y = pos[b[j] - 'a'];
                    if(x>y) return false;
                    break;
                }
                j++;
            }
            if(j == min(a.size(),b.size()) and a.size() > b.size()) return false;
        }
        return true;
    }
};