class Solution {
public:
    bool makeEqual(vector<string>& words) {

        unordered_map<char,int> mp;
        for(auto word:words)
        {
            for(auto w:word) mp[w]++;
        }

        int n = words.size();

        for(auto &[k,v]:mp)
        {
            if(v%n != 0) return false;
        }
        return true;
        
    }
};