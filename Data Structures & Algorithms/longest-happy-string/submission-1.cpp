class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans;
        while(!pq.empty())
        {
            int n = ans.size();
            auto x = pq.top();pq.pop();
            if(n>=2 and ans[n-1]==x.second and ans[n-2]==x.second)
            {
                if(pq.empty()) break;
                auto y = pq.top();pq.pop();
                ans += y.second;
                y.first--;
                if(y.first>0) pq.push(y);
                pq.push(x);
            }
            else
            {
                ans += x.second;
                x.first--;
                if(x.first>0) pq.push(x);
            }
        }
        return ans;
    }
};