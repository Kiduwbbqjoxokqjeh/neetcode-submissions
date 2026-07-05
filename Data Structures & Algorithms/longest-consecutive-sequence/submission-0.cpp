class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(),nums.end());
        int maxl = 0;

        for(auto x:st)
        {
            if(!st.count(x-1))
            {
                int curr = x;
                int l=1;
                while(st.count(curr+1))
                {
                    curr++;
                    l++;
                }
                maxl = max(maxl,l);
            }
        }
        return maxl;
    }
};
