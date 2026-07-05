class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        vector<int> v(nums.size(),0);

        for(int i=0;i<nums.size();i++)
        {
            v[nums[i] - 1]++;
        }
        int x,y;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == 2) x = i+1;
            if(v[i] == 0) y = i+1;
        }
        return {x,y};
        
    }
};