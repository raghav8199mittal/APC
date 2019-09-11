/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* curr=A;
    int len=0;
    while(curr)
    {
        curr=curr->next;
        len++;
    }
    if(len==B||B%len==0)
        return A;
    int k1=len-(B%len);
    curr=A;
    int temp=1;
    while(curr&&temp!=k1)
    {
        curr=curr->next;
        temp++;
    }
    ListNode* start=curr->next;
    curr->next=NULL;
    curr=start;
    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=A;
    A=start;
    return A;
}
