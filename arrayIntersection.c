#include<stdio.h>
//assume array a and b are sorted
//Solution is done in O(n+m) time complexity and O(min(n,m)) space complexity
int main()
{
    int n,i,j,m,l=0;
    printf("Enter length of array a: ");
    scanf("%d",&n);
    printf("\nEnter elements in array(a) in sorted order: ");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter length of array b: ");
    scanf("%d",&m);
    printf("\nEnter elements in array(b) in sorted order: ");
    int b[m];
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    int k=n>m?n:m;
    int res[k];
    i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
        else
        {
            res[l++]=a[i];
            i++;
            j++;
        }
    }
    printf("\nIntersection of both arrays: ");
    for(i=0;i<l;i++)
        printf("%d ",res[i]);
}
