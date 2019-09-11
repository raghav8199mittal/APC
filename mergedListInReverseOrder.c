#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node* next;
};
void insert(struct Node** h,int d)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=d;
    n->next=NULL;
    if(*h==NULL)
    {
        *h=n;
    }
    else
    {
        struct Node *c=*h;
        while(c&&c->next)
        {c=c->next;}
        c->next=n;
    }
}
void insertBeg(struct Node** h,int d)
{
    struct Node* hh=*h;
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=d;
    if(*h==NULL)
    {
        n->next=NULL;
        *h=n;
    }
    else
    {
        n->next=hh;
        *h=n;
    }
   
}
int main() {
    int n=3,i,k;
    struct Node *f=NULL;
    struct Node *s=NULL;
    struct Node *r=NULL;
    for(i=0;i<3;i++)
    {
        scanf("%d",&k);
        insert(&f,k);
    }
    for(i=0;i<3;i++)
    {
        scanf("%d",&k);
        insert(&s,k);
    }
    struct Node *ff=f;
    struct Node *ss=s;
    while(ff&&ss)
    {
        if(ff->data<=ss->data)
        {
            insertBeg(&r,ff->data);
            ff=ff->next;
        }
        else
        {
            insertBeg(&r,ss->data);
            ss=ss->next;
        }
    }
    while(ff)
    {
        insertBeg(&r,ff->data);
            ff=ff->next;
    }
    while(ss)
    {
        insertBeg(&r,ss->data);
            ss=ss->next;
    }
    ff=r;
    while(ff)
    {
        printf("%d ",ff->data);
        ff=ff->next;
    }
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

