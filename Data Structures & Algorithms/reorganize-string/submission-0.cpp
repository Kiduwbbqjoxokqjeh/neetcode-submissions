class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        unordered_map<char,int>mp;
        for(auto &x:s) mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto x:mp) pq.push({x.second,x.first});
        while(pq.size()>=2)
        {
            auto x = pq.top();pq.pop();
            auto y = pq.top();pq.pop();
            ans += x.second;
            ans += y.second;
            x.first--;
            y.first--;
            if(x.first > 0) pq.push(x);
            if(y.first > 0) pq.push(y);
        }
        if(!pq.empty())
        {
            auto z = pq.top();pq.pop();
            if(z.first > 1) return "";
            ans += z.second;
        }
        return ans;
    }
};