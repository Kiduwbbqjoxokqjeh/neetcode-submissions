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
class PrefixTree {
public:
    node *root;
    PrefixTree() {
        root=new node();
    }
    
    void insert(string word) {
        node *temp=root;
        for(auto &c:word)
        {
            int idx = c-'a';
            if(temp->child[idx] == nullptr)
            {
                temp->child[idx] = new node();
            }
            temp=temp->child[idx];
        }
        temp->isend=true;
    }
    
    bool search(string word) {
        node *temp=root;
        for(auto &c:word)
        {
            int idx= c-'a';
            if(temp->child[idx]==nullptr) return false;
            temp=temp->child[idx];
        }
        return temp->isend;
    }
    
    bool startsWith(string prefix) {
        node *temp=root;
        for(auto &c:prefix)
        {
            int idx=c-'a';
            if(temp->child[idx]==nullptr) return false;
            temp=temp->child[idx];
        }
        return true;
    }
};











