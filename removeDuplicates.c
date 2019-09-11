#include<stdio.h>
//assume array a is sorted
//Solution is done in O(n) time complexity and O(1) space complexity
int main()
{
    int n,i,j=0;
    printf("Enter length of array: ");
    scanf("%d",&n);
    printf("\nEnter elements in array in sorted order: ");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        if(a[j]!=a[i])
            {
                j++;
                a[j]=a[i];
            }
    }
    j++;
    printf("\nArray after removing duplicates: ");
    for(i=0;i<j;i++)
        printf("%d ",a[i]);
}
