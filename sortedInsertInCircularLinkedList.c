#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* temp=*head_ref;
    if(*head_ref==NULL)
    {
        new_node->next=new_node;
        *head_ref=new_node;
       
    }
    else
    {
        struct node* t=*head_ref;

        //temp=temp->next;
        if(t->data>new_node->data)
        {
            struct node* tt=*head_ref;
            while(tt->next!=*head_ref)
            {
                tt=tt->next;
            }
            tt->next=new_node;
            new_node->next=*head_ref;
            *head_ref=new_node;
        }
        else
        {
            while(t->next!=temp&&t->next!=NULL)
            {
                if(t->next->data>new_node->data)
                {
                    new_node->next=t->next;
                    t->next=new_node;
                    break;
                }

                t=t->next;
            }
            if(t->next==temp)
            {
                new_node->next=t->next;
                t->next=new_node;

            }
            }
        }
    
}

void printList(struct node *start)
{
  struct node *temp;

  if(start != NULL)
  {
    temp = start;
    
    do {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}

/* Driver program to test above functions */
int main()
{
  int arr; //= {12, 56, 2, 11, 1, 90};
  int list_size, i;

  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;
    
  int n;
  scanf("%d",&n);

  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&arr);
    temp->data = arr;
    sortedInsert(&start, temp);
  }

  printList(start);
  //getchar();
  return 0;
}