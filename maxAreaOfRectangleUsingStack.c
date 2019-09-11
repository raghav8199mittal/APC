#include<stdio.h>
#define CAPACITY 8
int top=-1;
int stack[CAPACITY];
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==CAPACITY-1)
        return 1;
    else
        return 0;
}
void push(int element)
{
    if(isFull())
    {
        ;
    }
    else
    {
        top++;
        stack[top]=element;
    }
}
int pop()
{
    int k=stack[top];
    if(!isEmpty())
    {
        top--;
        return k;
    }
}
int peek()
{
    int k=stack[top];
    if(!isEmpty())
        return k;
}
void print()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    int a[CAPACITY],i;
    int area=0,max=-1;
    for(i=0;i<CAPACITY;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<CAPACITY;i++)
    {
        if(isEmpty()||a[stack[top]]<=a[i])
            push(i);
        else
        {
            while(!isEmpty()&&a[stack[top]]>a[i])
            {
                int k=pop();
                int r=isEmpty()?i:i-stack[top]-1;
                area=a[k]*r;
                if(area>max)
                    max=area;
            }
            push(i);
        }
        print();
    }
    while(!isEmpty())
    {
        int k=pop();
        int r=isEmpty()?i:i-stack[top]-1;
        area=a[k]*r;
        if(area>max)
            max=area;
        print();
    }
    printf("Max possible area of rectangle is: %d",max);
    return 0;
}
