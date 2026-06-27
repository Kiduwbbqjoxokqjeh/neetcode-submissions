class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<(n-1);i += 2)
        {
            swap(nums[i],nums[i+1]);
        }

        // 3 5 2 1 6 4
        // 0 1 2 3 4 5
        // 1 2 3 4 5 6
        // 1 3 2 5 4 6
        
    }
};
