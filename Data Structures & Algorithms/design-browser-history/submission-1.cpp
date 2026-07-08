class node
{
    public:
        string url;
        node *prev,*next;
        node(string s)
        {
            url=s;
            prev=nullptr;
            next=nullptr;
        }
};
class BrowserHistory {
public:
    node *curr;
    BrowserHistory(string homepage) {
        curr=new node(homepage);
    }
    
    void visit(string url) {
        node *newnode = new node(url);
        curr->next=nullptr;
        curr->next=newnode;
        newnode->prev=curr;
        curr=newnode;
    }
    
    string back(int steps) {
        while(curr->prev and steps--) curr=curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next and steps--) curr=curr->next;
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */