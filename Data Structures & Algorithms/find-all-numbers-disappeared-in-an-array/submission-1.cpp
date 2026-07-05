class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<bool> check(nums.size(),false);
        for(auto x: nums)
        {
            check[x-1] = true;
        }
        vector<int> ans;
        for(int i=0;i<check.size();i++)
        {
            if(!check[i]) ans.push_back(i+1);
        }
        return ans;
        
    }
};