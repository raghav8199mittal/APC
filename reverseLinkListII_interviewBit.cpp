/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL||A->next==NULL)
        return A;
    if(B>=C)
        return A;
    if(B==1)
    {
        ListNode* curr=A;
        ListNode* nextCurr;
        int i=1;
        ListNode* temp=A;
        while(i<C&&temp)
        {
            i++;
            temp=temp->next;
        }
        ListNode* end=temp;
        nextCurr=curr->next;
        while(curr&&curr->next)
        {
            nextCurr=curr->next;
            curr->next=nextCurr->next;
            nextCurr->next=A;
            A=nextCurr;
            if(nextCurr==end)
                break;
        }
    }
    else
    {
        ListNode* start=A;
        ListNode* curr=A;
        ListNode* nextCurr;
        int i=1;
        ListNode* temp=A;
        while(i<B)
        {
            i++;
            start=temp;
            temp=temp->next;
        }
        curr=temp;
        while(i<C)
        {
            i++;
            temp=temp->next;
        }
        ListNode* end=temp;
        nextCurr=curr->next;
        while(curr&&curr->next)
        {
            nextCurr=curr->next;
            curr->next=nextCurr->next;
            nextCurr->next=start->next;
            start->next=nextCurr;
            if(nextCurr==end)
                break;
        }
    }
    return A;
}
