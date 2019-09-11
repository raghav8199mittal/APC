#include<stdio.h>
#define CAPACITY 5
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
}
int main()
{
    int i;
    for(i=0;i<4;i++)
    {
        push(i);
    }
    pop();
    push(3);
    push(4);
    push(5);
    print();
    return 0;
}
