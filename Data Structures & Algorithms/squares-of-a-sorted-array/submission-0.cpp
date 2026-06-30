class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        transform(nums.begin(),nums.end(),ans.begin(),[](int x){
            return x*x;
        });
        sort(ans.begin(),ans.end());
        return ans;
    }
};