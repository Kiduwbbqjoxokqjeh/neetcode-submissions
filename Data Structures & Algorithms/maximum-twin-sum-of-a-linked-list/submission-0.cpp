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
        ListNode *x = revrec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x;
    }
    int pairSum(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *sec = revrec(slow->next),*fir=head;
        slow->next=nullptr;
        int ans=INT_MIN;
        while(fir and sec)
        {
            ans = max(ans,sec->val + fir->val);
            fir=fir->next;
            sec=sec->next;
        }
        return ans;
    }
};