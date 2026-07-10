/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int depth(Node *x)
    {
        int d=0;
        while(x)
        {
            d++;
            x=x->parent;
        }
        return d;
    }
    Node *func(Node *&p,Node *&q)
    {
        int d1=depth(p);
        int d2=depth(q);

        while(d1>d2)
        {
            p=p->parent;d1--;
        }
        while(d2>d1) 
        {
            q=q->parent;d2--;
        }
        while(p!=q)
        {
            p=p->parent;q=q->parent;
        }
        return p;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        return func(p,q);
    }
};