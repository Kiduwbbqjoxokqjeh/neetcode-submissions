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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=0;
        ListNode *temp = head;
        while(temp)
        {
            x++;temp = temp->next;
        }
        int req=x-n;
        if(req == 0)
        {
            ListNode *y = head;
            head=head->next;
            delete y;
            return head;
        }
        ListNode *prev=nullptr,*curr=head;
        while(req--)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};
