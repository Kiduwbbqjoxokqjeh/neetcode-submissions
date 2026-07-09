class node
{
    public:
    int key,val;
    node *next,*prev;
    node(int x,int y)
    {
        key=x;val=y;
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
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insert(node *x)
    {
        x->prev = tail->prev;
        x->next=tail;
        tail->prev->next=x;
        tail->prev=x;
    }
    void remove(node *x)
    {
        x->prev->next=x->next;
        x->next->prev=x->prev;
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
            node *x = mp[key];
            x->val = value;
            remove(x);
            insert(x);
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
