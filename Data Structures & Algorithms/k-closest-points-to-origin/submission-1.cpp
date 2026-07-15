class Solution {
public:
    using pivi = pair<int,vector<int>>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if(k==n) return points;
        priority_queue<pivi,vector<pivi>> q;
        for(int i=0;i<k;i++)
        {
            auto x = points[i];
            int d = x[0]*x[0]+x[1]*x[1];
            q.push({d,x});
        }
        for(int i=k;i<n;i++)
        {
            auto x = points[i];
            int d = x[0]*x[0] + x[1]*x[1];
            q.push({d,x});
            if(q.size() > k) q.pop();
        }
        vector<vector<int>> ans;
        while(!q.empty())
        {
            auto x = q.top();q.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
