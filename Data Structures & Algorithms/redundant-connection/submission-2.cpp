class Solution {
public:
    vector<int> parent,rank;
    int find(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void dounion(int a,int b)
    {
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return;

        if(rank[pa] > rank[pb]) parent[pb] = pa;
        else if(rank[pa]<rank[pb]) parent[pa] = pb;
        else
        {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
        for(auto &e:edges)
        {
            int a=e[0],b=e[1];
            if(find(a) == find(b)) return e;
            dounion(a,b);
        }
        return {};
    }
};
