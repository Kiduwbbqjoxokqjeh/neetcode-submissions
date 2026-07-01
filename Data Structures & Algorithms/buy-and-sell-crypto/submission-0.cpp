class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int las = prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            ans = max(ans,prices[i] - las);
            las = min(las,prices[i]);
        }
        return ans;
    }
};
