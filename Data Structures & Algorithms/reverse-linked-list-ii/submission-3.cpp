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
    ListNode *rev(ListNode *&head)
    {
        if(!head or !head->next) return head;
        ListNode *newhead = rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy,*prev,*ln,*rn,*after;
        dummy=new ListNode(0);
        dummy->next=head;
        prev=dummy;
        for(int i=1;i<left;i++) prev=prev->next;
        ln=prev->next;
        rn=ln;
        for(int i=left;i<right;i++) rn=rn->next;
        after=rn->next;
        rn->next=nullptr;
        prev->next=rev(ln);
        ln->next=after;
        return dummy->next;
    }
};