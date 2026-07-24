class node
{
    public:
        bool isend;
        unordered_map<string,node*> child;
        node(){isend=false;}
};
class Solution {
public:
    node *root;
    Solution(){root=new node();}
    vector<string> ans;
    void dfs(node *&temp,string curr)
    {
        if(temp->isend)
        {
            ans.push_back(curr);
            return;
        }
        for(auto &it:temp->child)
        {
            dfs(it.second,curr + "/" +it.first);
        }
    }
    void insert(string &path)
    {
        node *temp=root;
        string curr="";
        for(int i=1;i<path.size();i++)
        {
            if(path[i] == '/')
            {
                if(!temp->child[curr]) temp->child[curr] = new node();
                temp=temp->child[curr];
                curr="";
            }
            else curr += path[i];
        }
        if(!temp->child[curr]) temp->child[curr] = new node();
        temp=temp->child[curr];
        temp->isend=true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto &f:folder) insert(f);
        dfs(root,"");
        return ans;
    }
};












