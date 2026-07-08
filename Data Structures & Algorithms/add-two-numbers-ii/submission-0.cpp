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
        ListNode *newhead=revrec(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=revrec(l1);
        l2=revrec(l2);
        ListNode *head=nullptr,*tail=nullptr;
        int carry=0;
        while(l1 or l2 or carry)
        {
            int sum=carry;
            if(l1)
            {
                sum += l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2=l2->next;
            }
            ListNode *newnode = new ListNode(sum%10);
            if(!head)
            {
                head=newnode;tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=tail->next;
            }
            carry=sum/10;
        }
        return revrec(head);
    }
};