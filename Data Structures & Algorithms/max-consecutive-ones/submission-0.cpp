class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxe = 0,oc=0;
        for(auto x:nums)
        {
            if(x == 1) oc++;
            else
            {
                maxe = max(maxe,oc);
                oc = 0;
            }
            maxe = max(maxe,oc);
        }
        return maxe;
        
    }
};