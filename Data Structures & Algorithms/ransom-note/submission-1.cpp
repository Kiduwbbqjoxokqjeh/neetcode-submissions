class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> mp;
        for(auto x: magazine) mp[x]++;

        for(auto c:ransomNote)
        {
            if(mp[c] == 0) return false;
            mp[c]--;
        }
        return true;
        
    }
};