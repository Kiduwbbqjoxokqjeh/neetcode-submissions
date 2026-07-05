class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++) q.push({tickets[i],i});

        int ans=0;
        while(1)
        {
            auto [t,idx] = q.front(); q.pop();
            t--; ans++;
            if(t == 0 and idx == k) return ans;
            if(t>0) q.push({t,idx});
        }
        return 0;
        
    }
};