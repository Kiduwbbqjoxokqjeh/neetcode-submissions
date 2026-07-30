class Solution {
public:
    using vd = vector<double>;
    using vb = vector<bool>;
    unordered_map<string,vector<pair<string,double>>> graph;
    bool dfs(string &curr,string &dest,unordered_set<string> &vis,double prod,double &ans)
    {
        if(curr == dest){ans=prod;return true;}
        vis.insert(curr);
        for(auto &[next,wt]:graph[curr])
        {
            if(!vis.count(next))
            {
                if(dfs(next,dest,vis,prod*wt,ans)) return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b,val});
            graph[b].push_back({a,1.0/val});
        }
        unordered_set<string> vis;
        vector<double> ans;
        for(auto &q:queries)
        {
            string src = q[0],dest=q[1];
            if(!graph.count(src) or !graph.count(dest)) {ans.push_back(-1.0);continue;}
            vis.clear();
            double val=-1;
            dfs(src,dest,vis,1.0,val);
            ans.push_back(val);
        }
        return ans;
    }
};