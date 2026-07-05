class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        bool x = is_sorted(nums.begin(),nums.end());
        bool y = is_sorted(nums.begin(),nums.end(),greater<int>());
        return x or y;
        
    }
};