class NumArray {
public:
     vector<int> p;
    NumArray(vector<int>& nums) {
        p = vector<int>(nums.size(),0);
        p[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            p[i] = p[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {

        int ans=0;
        if(left == 0)
        {
            ans = p[right];
        }
        else
        {
            ans = p[right] - p[left-1];
        }
        return ans;

        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */