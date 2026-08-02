class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0 and nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 and nums[j] == nums[j-1]) continue;
                int l=j+1,r=n-1;
                while(l<r)
                {
                    long long sum = 1LL*nums[i] +nums[l]+nums[r]+nums[j];
                    if(sum == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r and nums[l] == nums[l+1])l++;
                        while(l<r and nums[r] == nums[r-1])r--;
                        l++;r--;
                    }
                   else if(sum>target)r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};