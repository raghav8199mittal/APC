#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}
listnode* reverse(listnode* curr)
 {
     listnode* prev=NULL;
     listnode* nextt=NULL;
     while(curr!=NULL)
     {
         nextt=curr->next;
         curr->next=prev;
         prev=curr;
         curr=nextt;
     }
     return prev;
 }
int isPalin(listnode* A){
    if(A!=NULL && A->next==NULL)
    return 1;
listnode* slow=A;
listnode* fast=A->next;
int count=0,count1=0;
listnode* curr=A;
while(curr!=NULL)
{
    count1++;
    curr=curr->next;
}
while(slow && fast && fast->next)
{
    slow=slow->next;
    fast=fast->next->next;
}
listnode* head1=A;
listnode* head2=slow->next;
head2=reverse(head2);
slow->next=NULL;
while(head1 && head2)
{
    if(head1->val==head2->val)
   {
    head1=head1->next;
    head2=head2->next;
   }
   else
   return 0;
}
if(count1%2!=0)
{
   head1=head1->next;
}
if(head1==NULL && head2==NULL)
return 1;

return 0;
}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}
