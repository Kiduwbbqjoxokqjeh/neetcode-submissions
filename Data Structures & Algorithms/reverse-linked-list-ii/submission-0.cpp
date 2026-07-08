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
    ListNode *newnode=revrec(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newnode;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or left==right) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy;
        for(int i=1;i<left;i++) prev=prev->next;
        ListNode *leftnode=prev->next,*rightnode=leftnode;
        for(int i=left;i<right;i++) rightnode=rightnode->next;
        ListNode *after=rightnode->next;
        rightnode->next=nullptr;
        prev->next=revrec(leftnode);
        leftnode->next=after;
        return dummy->next;
    }
};
