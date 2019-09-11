#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



// Complete the braces function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
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

char** braces(int values_count, char** values, int* result_count) {
    char **res=(char**)malloc(values_count*sizeof(char*));
    st *top=NULL;
    int i,j;
    for(i=0;i<values_count;i++)
    {
        res[i]=(char*)malloc(3*sizeof(char));
    }
    for(i=0;i<values_count;i++)
    {
        top=NULL;int p=0;
        for(j=0;values[i][j]!='\0';j++)
        {
            char c=' ';
            if(!empty(top))
                c=values[i][top->data];
            if(empty(top)&&(values[i][j]=='{'||values[i][j]=='['||values[i][j]=='('))
                push(&top,j);
            else if(empty(top)&&(values[i][j]=='}'||values[i][j]==']'||values[i][j]==')'))
            {p=1;break;}
            else if((c=='['&&values[i][j]==']')||(c=='('&&values[i][j]==')')||(c=='{'&&values[i][j]=='}'))
                pop(&top);
            else if(c=='{'||c=='['||c=='(')
                push(&top,j);
            else
                {break;p=1;}
        }
        if(p==0&&top==NULL)
            res[i]="YES";
        else
            res[i]="NO";

    }
    *result_count=values_count;
    return res;

}

int main()