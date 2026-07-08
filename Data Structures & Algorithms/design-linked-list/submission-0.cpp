class Node
{
    public:
        int val;
        Node *next;
        Node(int x)
        {
            val=x;
            next=nullptr;
        }
};
class MyLinkedList {
public:
    Node *head;
    int size;

    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
        if(index < 0 or index >= size) return -1;
        Node *temp=head;
        while(index--)
        {
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newnode = new Node(val);
        newnode->next=head;
        head=newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node *newnode=new Node(val);
        if(!head)
        {
            head=newnode;
            size++;
            return;
        }
        Node *temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index <  0 or index>size) return;
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        Node *temp=head;
        for(int i=0;i<index-1;i++)
        {
            temp=temp->next;
        }
        Node *newnode = new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 or index >= size) return;
        if(index==0)
        {
            Node *del=head;
            head=head->next;
            delete del;
            size--;
            return;
        }
        Node *temp=head;
        for(int i=0;i<index-1;i++)
        {
            temp=temp->next;
        }
        Node *del=temp->next;
        temp->next=del->next;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */