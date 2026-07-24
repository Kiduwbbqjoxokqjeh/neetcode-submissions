class node
{
    public:
        unordered_map<string,node*> child;
        bool isend;
        node(){isend=false;}
};
class Solution {
public:
    node *root=new node();
    void insert(string &path)
    {
        node *temp=root;
        string curr = "";
        for(int i=1;i<path.size();i++)
        {
            if(path[i] == '/')
            {
                if(!temp->child[curr]) temp->child[curr] = new node();
                temp=temp->child[curr];
                curr = "";
            }
            else curr += path[i];
        }
        if(!temp->child[curr]) temp->child[curr] = new node();
        temp=temp->child[curr];
        temp->isend=true;
    }
    void dfs(node *&temp,string path,vector<string> &ans)
    {
        if(temp->isend) 
        {
            ans.push_back(path);
            return;
        }
        for(auto &it : temp->child)
        {
            dfs(it.second,path + "/" + it.first,ans);
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto &f:folder) insert(f);
        vector<string> ans;
        dfs(root,"",ans);
        return ans;
    }
};















