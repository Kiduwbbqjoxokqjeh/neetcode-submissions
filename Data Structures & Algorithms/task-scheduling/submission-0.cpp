class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto &x:tasks) mp[x]++;
        int maxval=0;
        for(auto &[k,v]:mp) maxval = max(maxval,v);
        int maxcount=0;
        for(auto &[k,v]:mp)
        {
            if(v==maxval) maxcount++;
        }
        int ans = (n+1)*(maxval-1) + maxcount;
        return max(ans,(int)tasks.size());

    }
};
