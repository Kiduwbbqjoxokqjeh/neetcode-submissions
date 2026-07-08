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
        head->next  = nullptr;
        return newnode;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head,*fast=head;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *second = revrec(slow->next);
        slow->next = nullptr;
        ListNode *first = head;
        while(second)
        {
            ListNode *t1 = first->next, *t2 = second->next;
            first->next = second;
            second->next = t1;

            first=t1;second=t2;
        }

    }
};
