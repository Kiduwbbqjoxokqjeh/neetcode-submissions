class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int n = nums.size();
        int l=0,ans=INT_MIN;
        for(int r=0;r<n;r++)
        {
            ms.insert(nums[r]);
            while(*ms.rbegin() - *ms.begin() > limit)
            {
                ms.erase(ms.find(nums[l++]));
            }
            ans = max(ans,r-l+1);
        }
        if(ans!=INT_MIN) return ans;
        return -1;
    }
};