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
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = revrec(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy;
        for(int i=1;i<left;i++) prev=prev->next;
        ListNode *ln,*rn,*after;
        ln = prev->next; 
        rn=ln;
        for(int i=left;i<right;i++) rn=rn->next;
        after=rn->next;
        rn->next=nullptr;
        prev->next=revrec(ln);
        ln->next=after;
        return dummy->next;
    }
};