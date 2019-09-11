#include<stdio.h>
struct node
{
    struct node* random;
    int data;
    struct node* next;
};
void insertAtEnd(struct node** h,int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->random=NULL;
    n->data=d;
    n->next=NULL;
    if(*h==NULL)
        *h=n;
    else
    {
        struct node *curr=*h;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=n;
    }
}
void print(struct node** h)
{
    struct node *curr=*h;
    while(curr)
    {
        printf("%u->%d->%u  ",curr->random,curr->data,curr->next);
        curr=curr->next;
    }
}
struct node* clone(struct node** head)
{
    struct node *curr=*head;
    while(curr)
    {
        struct node *temp=curr->next;
        struct node *n=(struct node*)malloc(sizeof(struct node));
        n->data=curr->data;
        curr->next=n;
        curr->next->next=temp;
        curr=temp;
    }
    curr=*head;
    while(curr)
    {
        if(curr->next)
            curr->next->random=curr->random?curr->random->next:curr->random;
        curr=curr->next?curr->next->next:curr->next;
    }
    curr=*head;
    struct node* head2=(struct node*)malloc(sizeof(struct node));

    struct node* curr2=curr->next;
    head2=curr2;
    while(curr&&curr2)
    {
        curr->next=curr->next?curr->next->next:curr->next;
        curr2->next=curr2->next?curr2->next->next:curr2->next;
        curr=curr->next;
        curr2=curr2->next;
    }
    return head2;
}
int main()
{
    struct node* head=NULL;
    int i;
    for(i=1;i<=4;i++)
    {insertAtEnd(&head,i);}
    struct node* c=head;
    c->random=c->next->next;
    c->next->random=c;
    c->next->next->random=c->next->next->next;
    c->next->next->next->random=c->next->next;
    struct node* head2=clone(&head);
    print(&head);
    printf("\n");
    print(&head2);
}
