class node
{
    public:
        bool isend;
        node *child[26];
        node()
        {
            isend=false;
            for(int i=0;i<26;i++) child[i] = nullptr;
        }
};
class WordDictionary {
public:
    node *root;
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node *temp=root;
        for(auto &c:word)
        {
            int idx = c-'a';
            if(temp->child[idx]==nullptr) temp->child[idx]=new node();
            temp=temp->child[idx];
        }
        temp->isend=true;
    }
    bool dfs(node *&temp,string &word,int idx)
    {
        if(temp==nullptr) return false;
        if(idx==word.size()) return temp->isend;
        if(word[idx]=='.')
        {
            for(int i=0;i<26;i++)
            {   
                if(dfs(temp->child[i],word,idx+1)) return true;
            }
            return false;
        }
        int j = word[idx]-'a';
        return dfs(temp->child[j],word,idx+1);
    }
    bool search(string word) {
        return dfs(root,word,0);
    }
};

















