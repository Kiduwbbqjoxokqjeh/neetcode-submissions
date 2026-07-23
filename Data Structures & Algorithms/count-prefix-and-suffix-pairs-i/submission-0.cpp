    class node
    {
        public:
            unordered_map<int,node*> child;
            int cnt;
            node(){cnt=0;}
    };
    class Solution {
    public:
        int countPrefixSuffixPairs(vector<string>& words) {
            node *root=new node();
            int ans=0;
            for(auto &word:words)
            {
                node *temp=root;
                int n =word.size();
                for(int i=0;i<n;i++)
                {
                    int key = (word[i] - 'a')*26 + word[n-1-i] - 'a';
                    if(temp->child.find(key)==temp->child.end()) break;
                    temp=temp->child[key];
                    ans += temp->cnt;
                }
                temp= root;
                for(int i=0;i<n;i++)
                {
                    int key = (word[i]-'a')*26 + word[n-1-i] - 'a';
                    if(temp->child.find(key) == temp->child.end())
                    {
                        temp->child[key] = new node;
                    }
                    temp=temp->child[key];
                }
                temp->cnt++;
            }
            return ans;
        }
    };














