class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word)
        {
            words.push_back(word);
        }
        if(pattern.size() != words.size()) return false;

        unordered_map<char,string> mp;
        unordered_map<string,char> rmp;

        for(int i=0;i<words.size();i++)
        {
            char c = pattern[i];
            string w = words[i];

            if(mp.count(c))
            {
                if(mp[c] != w) return false;
            }
            else mp[c] = w;

            if(rmp.count(w))
            {
                if(rmp[w] != c) return false;
            }
            else rmp[w] = c;
        }

        return true;
        
    }
};