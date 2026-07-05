class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        mp.insert(make_pair(nums[0],0));
        for(int i=1;i<nums.size();i++)
        {
            auto it = mp.find(target-nums[i]);
            if(it != mp.end())
            {
                vector<int> ans;
                ans.push_back(it->second);
                ans.push_back(i);
                sort(ans.begin(),ans.end()); return ans;
            }
            mp.insert(make_pair(nums[i],i));
        }

    }
};
