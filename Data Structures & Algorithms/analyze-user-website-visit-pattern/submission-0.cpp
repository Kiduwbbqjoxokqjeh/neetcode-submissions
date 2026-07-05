class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {

        int n= username.size();
        vector<tuple<int,string,string>> logs;
        for(int i=0;i<n;i++)
        {
            logs.push_back({timestamp[i],username[i],website[i]});
        }
        sort(logs.begin(),logs.end());
        unordered_map<string,vector<string>> mp;
        for(auto &x:logs)
        {
            mp[get<1>(x)].push_back(get<2>(x));
        }
        // bob -> home,user,cart
        map<vector<string>,int> cnt;
        for(auto &[key,val]:mp)
        {
            vector<string> &v = val;
            set<vector<string>> seen;
            for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                {
                    for(int k=j+1;k<v.size();k++)
                    {
                        seen.insert({v[i],v[j],v[k]});
                    }
                }
            }
            for(auto &p:seen) cnt[p]++;

        }
        vector<string> ans;
        int best=0;
        for(auto &[k,v]:cnt)
        {
            if(v > best or (v == best and k < ans))
                {
                    best = v;
                    ans = k;
                }
        }
        return ans;
    }
};