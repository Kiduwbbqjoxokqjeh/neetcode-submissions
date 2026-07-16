class Solution {
public:
    using pii = pair<int,int>;
    using vi = vector<int>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vi> arr;
        int n = tasks.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(arr.begin(),arr.end());

        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<int> ans;
        int i=0;
        long long time=0;
        while(i<n or !pq.empty())
        {
            if(pq.empty())
            {
                time = max(time,(long long)arr[i][0]);
            }
            while(i<n and arr[i][0] <= time) 
            {
                pq.push({arr[i][1],arr[i][2]});
                i++;
            }
            auto [p,idx] = pq.top();pq.pop();
            ans.push_back(idx);
            time += p;
        }
        return ans;
    }
};





















