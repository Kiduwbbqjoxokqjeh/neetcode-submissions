class Solution {
public:
    int specialArray(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int x=0;x<=n;x++)
        {
            auto it1 = lower_bound(nums.begin(),nums.end(),x);
            // returns index to first element <= x
            int diff = nums.end() - it1;
            if(diff == x) return x;
        }
        return -1;
        
    }
};