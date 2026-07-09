class node
{
    public:
    int key,val;
    node *next,*prev;
    node(int k,int v)
    {
        key=k;val=v;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int,node*> mp;
    int cap;
    node *head,*tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void remove(node *head)
    {
        head->prev->next=head->next;
        head->next->prev=head->prev;
    }
    void insert(node *head)
    {
        head->prev = tail->prev;
        head->next = tail;
        tail->prev->next=head;
        tail->prev=head;
    }
    int get(int key) {
        if(!mp.count(key)) return -1;
        node *x = mp[key];
        remove(x);
        insert(x);
        return x->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            node *newnode = mp[key];
            newnode->val = value;
            remove(newnode);
            insert(newnode);
            return;
        }
        if(mp.size() == cap)
        {
            node *lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        node *x = new node(key,value);
        insert(x);
        mp[key] = x;
    }
};
