class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == k)
        {
            sort(arr.begin(),arr.end());
            return arr;
        }
        priority_queue<pair<int,int>> pq;
        int l=0;
        for(int r=0;r<n;r++)
        {
            pair<int,int> temp = {abs(x-arr[r]),r};
            pq.push(temp);
            if(pq.size() > k)
            {
                auto y = pq.top();
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            auto x = pq.top();pq.pop();
            ans.push_back(arr[x.second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};