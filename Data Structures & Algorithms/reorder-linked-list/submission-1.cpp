/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode *revrec(ListNode *&head)
    {
        if(!head or !head->next) return head;
        ListNode *newnode = revrec(head->next);
        head->next->next = head;
        head->next=nullptr;
        return newnode;
    }
    void reorderList(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast and fast->next)
        {
            fast = fast->next->next;slow=slow->next;
        }
        ListNode *sec = revrec(slow->next);
        slow->next = nullptr;
        ListNode *fir = head;
        while(sec)
        {
            ListNode *t1=fir->next,*t2=sec->next;
            fir->next = sec;
            sec->next=t1;
            fir=t1;sec=t2;
        }
    }
};
