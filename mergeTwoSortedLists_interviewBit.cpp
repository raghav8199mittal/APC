/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* temp=new ListNode(0);
    ListNode* head=temp;
    while(A&&B)
    {
        if(A->val<=B->val)
        {
            temp->next=A;
            A=A->next;
        }
        else
        {
            temp->next=B;
            B=B->next;
        }
        temp=temp->next;
    }
    while(A)
    {
        temp->next=A;
        A=A->next;
        temp=temp->next;
    }
    while(B)
    {
        temp->next=B;
        B=B->next;
        temp=temp->next;
    }
    head=head->next;
    return head;
}
