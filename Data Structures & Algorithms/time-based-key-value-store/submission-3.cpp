class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans;
        if(!mp.count(key)) return ans;
        auto &x = mp[key];
        int l=0,r=x.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(x[mid].second <= timestamp)
            {
                ans = x[mid].first;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
