class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> mp;
        for(auto x: s) mp[x]++;

        int ans=0;
        bool flag = false;

        for(auto &[k,v] : mp)
        {
            ans += (v/2)*2 ;
            if(v%2 == 1) flag = true;
        }
        if(flag) ans += 1;
        return ans;
        
    }
};