class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st1(nums1.begin(),nums1.end()) , st2(nums2.begin(),nums2.end());
        set<int> a,b;

        for(auto &x: nums1)
        {
            if(!st2.count(x)) a.insert(x);
        }
        for(auto &x:nums2)
        {
            if(!st1.count(x)) b.insert(x);
        }
        return {vector<int>(a.begin(),a.end()),vector<int>(b.begin(),b.end())};
        
    }
};