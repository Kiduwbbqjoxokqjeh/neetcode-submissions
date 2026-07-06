class Solution {
public:
    bool ispos(vector<int> &nums,int p,int mid)
    {
        int cnt=0;
        for(int i=1;i<nums.size();)
        {
            if(nums[i]-nums[i-1] <= mid)
            {
                cnt++; i+=2;
            }
            else i++;
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,r=(nums.back()-nums.front());
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(ispos(nums,p,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};