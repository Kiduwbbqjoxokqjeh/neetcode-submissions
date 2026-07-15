class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        priority_queue<int> q(gifts.begin(),gifts.end());
        while(!q.empty() and k--)
        {
            int x = q.top();q.pop();
            x = sqrt(x);
            q.push(x);
        }
        while(!q.empty())
        {
            sum += q.top();q.pop();
        }
        return sum;
    }
};