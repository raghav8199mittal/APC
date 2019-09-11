#include<iostream>
using namespace std;
struct node
{
int info;
node *link;
};
int main()
{
int i,k,key1,key2,item;
struct node *start,*n,*ptr,*loc1,*loc2,*loc1p,*loc2p;
scanf("%d",&k);
start=NULL;
for(i=0;i<k;i++)
{
scanf("%d",&item);
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->info=item;
new_node->link=start;
start=new_node;
}
struct node* curr=start;
while(curr!=NULL)
{
    printf("%d ",curr->info);
    curr=curr->link;
}
scanf("%d %d",&key1,&key2);
loc1p=NULL,loc2p=NULL,loc1=start,loc2=start;
while(loc1 && loc1->info!=key1)
{
  loc1p=loc1;
  loc1=loc1->link;
}
while(loc2 && loc2->info!=key2)
{
  loc2p=loc2;
  loc2=loc2->link;
}
printf("\n");
if(loc1p!=NULL)
loc1p->link=loc2;
else
start=loc2;

if(loc2p!=NULL)
loc2p->link=loc1;
else
start=loc1;

struct node* temp=loc2->link;
loc2->link=loc1->link;
loc1->link=temp;

while(start!=NULL)
{
    printf("%d ",start->info);
    start=start->link;
}





return 0;