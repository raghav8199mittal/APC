#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));

    new->data = data;
    new->next = *top;
    *top = new;

}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{

        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;
}
int main() {
    int n,c=0;
    scanf("%d",&n);
    while(n!=0)
    {
        c++;
        if(c!=1)
            printf("\n");
        int a[n];
        int i,l=1;
        st *s=NULL;
        int cc=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            while(!empty(s)&&peek(s)==l)
            {
                pop(&s);
                l++;
            }
            if(a[i]==l)
            {
                l++;
            }
            else if(!empty(s)&&peek(s)<a[i])
            {
                //printf("no");
                cc=1;
                break;
            }
            else
            {
                push(&s,a[i]);
            }
           
        }
        if(cc==0)
            printf("yes");
        else
            printf("no");
        scanf("%d",&n);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

