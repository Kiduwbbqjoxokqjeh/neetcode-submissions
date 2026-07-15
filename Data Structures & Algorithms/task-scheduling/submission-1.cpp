class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto &x:tasks) mp[x]++;
        int mx = 0;
        for(auto &[k,v]:mp) mx = max(mx,v);
        int cnt=0;
        for(auto &[k,v]:mp)
        {
            if(v==mx) cnt++;
        }
        int ans = (mx-1)*(n+1) + cnt;
        return max(ans,(int)tasks.size());
    }
};
