#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
void insertAtBeg(struct node** h,int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=*h;
    *h=n;

}
void insertAtEnd(struct node** h,int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
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
void insertAtPos(struct node** h,int d,int p)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(p==1)
    {
        newNode->data=d;
        newNode->next=*h;
        *h=newNode;
    }
    else
    {
        struct node *curr=*h;
        int i=1;
        while(curr&&i<p-1)
        {
            curr=curr->next;
            i++;
        }
        if(p<1||(curr==NULL))
        {
            ;
        }
        else
        {
            newNode->data=d;
            newNode->next=curr->next;
            curr->next=newNode;
        }
    }
}
void deleteAtBeg(struct node **h)
{
   struct node *c=*h;
   *h=c->next;
}
void deleteAtEnd(struct node **h)
{
    struct node *curr=*h;
    if(curr==NULL)
        return;
    if(curr->next==NULL)
    {
        *h=NULL;
        return;
    }

    if(curr->next->next==NULL)
    {
        curr->next=NULL;
        return;
    }
    while(curr&&curr->next&&curr->next->next)
    {
        curr=curr->next;
    }
    curr->next=NULL;

}
void deleteAtPos(struct node **h,int p)
{
    struct node *c=*h;
    if(p==1)
    {
        *h=c->next;
    }
    else
    {
        int i=1;
        while(c&&i<p-1)
        {
            c=c->next;
            i++;
        }
        if(p<1||(c==NULL&&c->next==NULL))
        {
            ;
        }
        else
        {
            c->next=c->next->next;
        }
    }
}
int length(struct node* h)
{
    struct node *curr=h;
    int i=0;
    while(curr)
    {
        i++;
        curr=curr->next;
    }
    return i;
}
void print(struct node** h)
{
    struct node *curr=*h;
    while(curr)
    {
        printf("%d->%u ",curr->data,curr->next);
        curr=curr->next;
    }
}

struct node* revLL(struct node* curr)
{
    struct node* first;
    first=curr;
    struct node* second;
    if(first)
        second=first->next;
    if(!second)
        return first;
    else
    {
        struct node *h=revLL(second);
        first->next=second->next;
        second->next=first;
        return h;
    }
}
void revLL_iterative(struct node** head)
{
    struct node* curr=*head;
    struct node* prev=*head;
    struct node* temp;
    while(curr&&curr->next)
    {
        temp=curr->next->next;
        *head=curr->next;
        curr->next->next=prev;
        curr->next=temp;
        prev=*head;
    }
}
void revLL_iterative2(struct node** head)
{
    struct node* curr=*head;
    struct node* prev=NULL;
    struct node* nextt=curr->next;
    while(curr)
    {
        curr->next=prev;
        prev=curr;
        curr=nextt;
        if(curr)
            nextt=curr->next;
    }
    *head=prev;
};
struct node* revLLk(struct node** head,int k)
{
    struct node* curr=*head;
    struct node* curr2=*head;
    struct node* prev=NULL;
    struct node* nextt=curr->next;
    int i=0;
    while(curr&&i<k)
    {
        curr->next=prev;
        prev=curr;
        curr=nextt;
        if(curr)
            nextt=curr->next;
        i++;
    }

    curr2->next=curr;
    if(!curr)
    {
        return prev;
    }
    curr2->next=revLLk(&(curr2->next),k);
    return prev;
}
struct node* revLLIP2(struct node* curr)
{
    struct node* first;
    first=curr;
    struct node* second=first->next;
    if(!second||!first)
        return first;
    else
    {
        second->next=revLLIP2(second->next);
        first->next=second->next;
        second->next=first;
        return second;
    }
}
void removeDuplicatesInSorted(struct node **head)
{
    struct node* curr=*head;
    while(curr&&curr->next)
    {
        if(curr->data==curr->next->data)
            curr->next=curr->next->next;
        else
            curr=curr->next;
    }
}
 void removeAllDuplicatesInSorted(struct node **h)
{

    struct node* dummy=(struct node*)malloc(sizeof(struct node));
    struct node* curr=*h;
    dummy->next=*h;
    struct node* ptr=dummy;
    while(curr)
    {
        while(curr->next!=NULL&&ptr->next->data==curr->next->data)
        {
            curr=curr->next;
        }
        if(ptr->next==curr)
        {
            ptr=ptr->next;
        }
        else
        {
            ptr->next=curr->next;
        }
        curr=curr->next;
    }
    *h=dummy->next;
}
void oneFromFirstOneFromLast(struct node* head)
{
    struct node *first=head;
    struct node *second=first->next;
    while(second)
    {
        first=first->next;
        second=second->next->next;
    }
    second=first->next;
    first->next=NULL;
    struct node *curr=head;
    struct node *head1=head;
    struct node *head2=second;
    head1=head1->next;
    head2=revLL(head2);
    while(head1||head2)
    {
        if(head2)
        {
            curr->next=head2;
            head2=head2->next;
            curr=curr->next;
        }
        if(head1)
        {
            curr->next=head1;
            head1=head1->next;
            curr=curr->next;
        }
    }
    print(&head);
    printf("\n");
}
int hasCycle(struct node* head)
{
    struct node* first=head,*second=head;
    if(head==NULL)
        return 0;
    while(first!=NULL&&second!=NULL&&second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
        if(first==second)
            return 1;
    }
    return 0;
}
void createCycle(struct node* head)
{
    //size of linked list should be greater than 2
    struct node* curr=head;
    struct node* curr2=head;
    curr2=curr2->next->next;
    while(curr&&curr->next)
    {
        curr=curr->next;
    }
    curr->next=curr2->next;
}
void removeCycle(struct node* head)
{
    struct node* first=head,*second=head;
    while(first!=NULL&&second!=NULL&&second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
        if(first==second)
        {
            struct node* ptr1=head;
            struct node* ptr2=first;
            ptr1=ptr1->next;
            while(ptr1!=ptr2->next)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ptr2->next=NULL;
            break;
        }
    }

}

int main()
{
    struct node *head = NULL;
    int i=0;
    for(i=1;i<=5;i++)
    {
        //insertAtEnd(&head,i);

    }
    //head=revLLIP2(head);
    //insertAtPos(&head,6,6);
    //insertAtBeg(&head,7);
    //deleteAtEnd(head);
    //deleteAtBeg(&head);
    //insertAtPos(&head,2,2);
    //deleteAtPos(&head,2);
    //head=revLL(head);
    //head=revLLIP2(head);
    insertAtEnd(&head,1);
    insertAtEnd(&head,1);
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    //insertAtEnd(&head,2);
    insertAtEnd(&head,2);
    insertAtEnd(&head,4);
    insertAtEnd(&head,4);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,8);
    insertAtEnd(&head,8);

    //removeAllDuplicatesInSorted(&head);
    //revLL_iterative(&head);
    //revLL_iterative2(&head);
    //head=revLLk(&head,4);
    removeAllDuplicatesInSorted(&head);
    print(&head);
    printf("\n");
    //oneFromFirstOneFromLast(head);
    //print(&head);
    //int k=hasCycle(head);
    //createCycle(head);
    //printf("\nCycle or loop present= %s",(hasCycle(head)==0?"No":"Yes"));
    //removeCycle(head);
    //printf("\nAfter removing cycle\nCycle or loop present= %s",(hasCycle(head)==0?"No":"Yes"));
    printf("\nlength of LL is %d",length(head));
}
