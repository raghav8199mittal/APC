/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL)
        return A;
    ListNode* curr=A;
    while(curr&&curr->next)
    {
        if(curr->val==curr->next->val)
        {
            curr->next=curr->next->next;
        }
        else
            curr=curr->next;
    }
    return A;
}
