class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto &x:s) mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto &[k,v]:mp)
        {
            pq.push({v,k});
        }
        string ans;
        while(pq.size()>=2)
        {
            auto p1 = pq.top();pq.pop();
            auto p2 = pq.top();pq.pop();
            ans += p1.second;ans += p2.second;
            p1.first--;
            p2.first--;
            if(p1.first>0) pq.push(p1);
            if(p2.first>0) pq.push(p2);
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