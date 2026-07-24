class node
{
    public:
        bool isend;
        node *child[26];
        node()
        {
            isend=false;
            for(int i=0;i<26;i++) child[i]=nullptr;
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
            if(temp->child[idx]==nullptr) temp->child[idx]= new node();
            temp=temp->child[idx];
        }
        temp->isend=true;
    }
    bool dfs(string &word,node *temp,int i)
    {
        if(!temp) return false;
        if(i==word.size()) return temp->isend;
        if(word[i]=='.')
        {
            for(int j=0;j<26;j++)
            {
                if(dfs(word,temp->child[j],i+1))return true;
            }
            return false;
        }
        int idx= word[i]-'a';
        return dfs(word,temp->child[idx],i+1);
    }
    bool search(string word) {
       return dfs(word,root,0);
    }
};
















