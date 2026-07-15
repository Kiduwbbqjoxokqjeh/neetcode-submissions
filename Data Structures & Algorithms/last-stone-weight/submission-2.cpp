class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        priority_queue<int> q(stones.begin(),stones.end());
        while(q.size()>1)
        {
            int x = q.top();q.pop();
            int y = q.top();q.pop();
            int diff = abs(x-y);
            if(diff>0) q.push(diff);
        }
        if(q.empty()) return 0;
        return q.top();
    }
};
