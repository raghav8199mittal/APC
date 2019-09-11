/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL||A->next==NULL)
        return A;
    ListNode* t=new ListNode(0);
    t->next=A;
    A=t;
    ListNode* curr=t;
    int min=t->next->val;
    ListNode* prev=t;
    ListNode* nC=t->next;
    while(curr->next)
    {
        if(curr->next->val<min)
        {
            prev=curr;
            nC=curr->next;
            min=curr->next->val;
        }
        curr=curr->next;
    }
    prev->next=nC->next;
    nC->next=t->next;
    t->next=nC;
    A=A->next;
    ListNode*nCC=A;
    curr=A;
    while(curr->next)
    {
        min=curr->next->val;
        prev=curr;
        nC=curr->next;
        while(curr->next)
        {
            if(curr->next->val<min)
            {
                prev=curr;
                nC=curr->next;
                min=curr->next->val;
            }
            curr=curr->next;
        }
        prev->next=nC->next;
        nC->next=nCC->next;
        nCC->next=nC;
        nCC=nCC->next;
        curr=nCC;
    }
    return A;
}
