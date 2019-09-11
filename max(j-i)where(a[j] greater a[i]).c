#include<stdio.h>
struct eval
{
    int val;
    int index;
};
int cmp(const void* a,const void* b)
{   struct eval *ia=(struct eval*)a;
    struct eval *ib=(struct eval*)b;
    return (ia->val-ib->val);
}
int main()
{
    int n,i;
    printf("Enter length of array ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements of array ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    struct eval arr[n];
    for(i=0;i<n;i++)
    {
        arr[i].val=a[i];
        arr[i].index=i;
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    int min=arr[0].index,max_el=0;
    for(i=1;i<n;i++)
    {
    if(arr[i].index<min)
        min=arr[i].index;
    if(arr[i].index-min>max_el)
        max_el=arr[i].index-min;
    }
    printf("\nMax (j-i), where a[j]>a[i] is : %d",max_el);
}
