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
    ListNode* revrec(ListNode *&head)
    {
        if(!head or !head->next) return head;
        ListNode *newnode = revrec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newnode;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        return revrec(temp);
    }
};
