/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL||A->next==NULL)
        return A;
    ListNode *slow=A;
    ListNode *fast=A;
    while(fast&&fast->next&&fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* mid=slow;
    ListNode* second=mid->next;
    while(second->next)
    {
        ListNode* temp=second->next;
        second->next=temp->next;
        temp->next=mid->next;
        mid->next=temp;
    }
    ListNode* first=A;
    second=mid->next;
    while(first!=mid)
    {
        mid->next=second->next;
        second->next=first->next;
        first->next=second;
        first=second->next;
        second=mid->next;
    }
    return A;
}
