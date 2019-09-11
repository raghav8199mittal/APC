/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* curr=A;
    //calculate length.
    int len=0;
    while(curr)
    {
        curr=curr->next;
        len++;
    }
    if(B>=len)
    {
        A=A->next;
        return A;
    }
    B=len-B-1;
    curr=A;
    while(B>0&&curr)
    {
        curr=curr->next;
        B--;
    }
    curr->next=curr->next->next;
    return A;
    
}
