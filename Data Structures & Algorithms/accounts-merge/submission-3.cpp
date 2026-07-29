using vi=vector<int>;
using vs=vector<string>;
class dsu
{
    public:
        vi parent,rank;
        dsu(int n)
        {
            parent.resize(n,0); rank.resize(n,0);
            for(int i=0;i<n;i++) parent[i] = i;
        }
        int find(int x)
        {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int x,int y)
        {
            int px=find(x),py = find(y);
            if(px==py) return;
            if(rank[px] > rank[py]) parent[py] = px;
            else if(rank[py] > rank[px]) parent[px] = py;
            else
            {
                parent[py] = px;
                rank[px]++;
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        dsu *func = new dsu(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string email = accounts[i][j];
                if(!mp.count(email)) mp[email] = i;
                else
                {
                    func->unite(i,mp[email]);
                }
            }
        }
        unordered_map<int,vs> merged;
        for(auto &[k,v]:mp)
        {
            string email = k;
            int account = v;
            int parent = func->find(account);
            merged[parent].push_back(email);
        }
        vector<vs> ans;
        for(auto &[k,v]:merged)
        {
            int parent=k;
            vs email = v;
            sort(email.begin(),email.end());
            vs temp;
            temp.push_back(accounts[parent][0]);
            temp.insert(temp.end(),email.begin(),email.end());
            ans.push_back(temp);
        }
        return ans;
    }
};













