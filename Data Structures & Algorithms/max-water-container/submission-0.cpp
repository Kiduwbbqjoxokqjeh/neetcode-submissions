class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<r)
        {
            int x = min(heights[l],heights[r]) * (r-l);
            ans = max(ans,x);
            if(heights[l] > heights[r])
            {
                r--;
            }
            else l++;
        }
        return ans;
        
    }
};
