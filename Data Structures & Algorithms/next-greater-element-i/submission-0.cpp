class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]] = i;
        }
        // 1->0 2->1 3->2 4->3
        for(int i=0;i<nums1.size();i++)
        {
            int elem = nums1[i];
            int idx = mp[elem];
            int maxe = -1;
            for(int j=idx;j<nums2.size();j++)
            {
                if(nums2[j] > elem) 
                {
                    maxe = nums2[j];
                    break;
                }
            }
           ans.push_back(maxe);
        }
        return ans;
        
    }
};