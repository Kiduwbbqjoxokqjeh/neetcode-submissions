class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int cand1=0,cand2=1;
        int c1=0,c2=0;
        for(auto x:nums)
        {
            if(x == cand1) c1++;
            else if(x == cand2) c2++;
            else if(c1 == 0)
            {
                cand1=x;c1=1;
            }
            else if(c2 == 0)
            {
                cand2=x;c2=1;
            }
            else
            {
                c1--;c2--;
            }
        }
        c1=0;c2=0;
        for(auto x:nums)
        {
            if(x == cand1) c1++;
            else if(x == cand2) c2++;
        }
        vector<int> ans;

        int n=nums.size();
        if(c1 > n/3) ans.push_back(cand1);
        if(c2 > n/3) ans.push_back(cand2);
        return ans;
        
    }
};