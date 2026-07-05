class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        unordered_map<char,int> mp;
        for(auto x:chars)
        {
            mp[x]++;
        }

        int ans=0;
        for(auto &word: words)
        {
            auto temp = mp;
            bool ok = true;
            for(auto c:word)
            {
                if(temp[c] == 0) 
                {
                    ok = false;
                    break;
                }
                temp[c]--;
            }
            if(ok) ans += word.size();
        }
        return ans;
        
    }
};