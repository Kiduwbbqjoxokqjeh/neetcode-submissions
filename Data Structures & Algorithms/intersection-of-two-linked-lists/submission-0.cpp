/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int a=0,b=0;
        ListNode *t1=headA,*t2=headB;
        while(t1)
        {
            a++;t1 = t1->next;
        }
        while(t2)
        {
            b++;t2 = t2->next;
        }
        t1=headA;t2=headB;
        if(a>b) 
        {
            int diff = a-b;
            while(diff--) t1 = t1->next;
        }
        else
        {
            int diff = b-a;
            while(diff--) t2 = t2->next;
        }
        while(t1 and t2)
        {
            if(t1 == t2) return t1;
            else 
            {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return nullptr;
    }
};