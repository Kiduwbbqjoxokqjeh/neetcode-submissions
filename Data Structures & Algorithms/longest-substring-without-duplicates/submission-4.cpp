class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char,int> mp;
        // int l=0,ans=0;
        // for(int r=0;r<s.size();r++)
        // {
        //     if(mp.find(s[r]) != mp.end())
        //     {
        //         l = max(mp[s[r]]+1,l); // if the element is outside current window,
        //         // keep the l same. else if the duplicate element is in the same window,
        //         // slide it 1 position right, so the duplicate is removed
        //     }
        //     mp[s[r]] = r;//whether duplicate or not, update the position
        //     ans = max(ans,r-l+1);
        // }
        // return ans;
        unordered_map<char,int> mp;
        int l=0,ans=0;
        for(int r=0;r<s.size();r++)
        {
            if(mp.find(s[r]) != mp.end())
            {
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
