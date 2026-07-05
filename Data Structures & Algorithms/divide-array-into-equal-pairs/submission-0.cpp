class Solution {
public:
    bool divideArray(vector<int>& nums) {

        set<int> st(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        
        int n = nums.size()/2;

        for(auto x:st)
        {
            if(mp[x] % 2 == 0)
            {
                int y = mp[x] / 2;
                n = n-y;
                mp.erase(x);
            }
        }
        if(n == 0 and mp.empty()) return true;
        return false;
    }
};