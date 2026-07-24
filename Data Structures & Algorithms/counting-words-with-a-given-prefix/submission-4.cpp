class node
{
    public:
        int cnt;
        node *child[26];
        node()
        {
            cnt=0;
            for(int i=0;i<26;i++) child[i] = nullptr;
        }
};
class Solution {
public:
    node *root;
    Solution(){root=new node();}
    void insert(vector<string> &words)
    {
        for(auto &word:words)
        {
            node *temp=root;
            for(auto &c:word)
            {
                int idx = c-'a';
                if(!temp->child[idx]) temp->child[idx] = new node();
                temp=temp->child[idx];
                temp->cnt++;
            }
        }

    }
    int check(string &pref)
    {
        node *temp=root;
        for(auto &c:pref)
        {
            int idx = c-'a';
            if(!temp->child[idx]) return 0;
            temp=temp->child[idx];
        }
        return temp->cnt;
    }
    int prefixCount(vector<string>& words, string pref) {
        insert(words);
        return check(pref);
    }
};