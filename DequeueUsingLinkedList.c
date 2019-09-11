#include<stdio.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void insertAtBeg(int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=front;
    n->prev=NULL;
    front=n;
    if(front->next)
        front->next->prev=front;
    else
        rear=front;
}
void insertAtEnd(int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(front==NULL)
    {
        front=n;
        front->prev=NULL;
        rear=front;
    }
    else
    {
        n->prev=rear;
        rear->next=n;
        rear=rear->next;
    }
}

void deleteAtBeg()
{
    if(front==NULL)
        return;
    struct node* temp=front;
    front=front->next;
    if(front)
        {front->prev=NULL;}
    if(!front)
        {rear=NULL;}
    free(temp);
}
void deleteAtEnd()
{
    if(!front)
        return;
    struct node* temp=rear;
    rear=rear->prev;
    if(rear)
        rear->next=NULL;
    else
        front=NULL;
    free(temp);
}
void print()
{
    struct node *curr=front;
    while(curr)
    {
        printf("%u->%d->%u  ",curr->prev,curr->data,curr->next);
        curr=curr->next;
    }
    printf("\n");
}


int main()
{
}
