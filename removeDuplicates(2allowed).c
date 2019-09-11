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
    for(i=0;i<n;i++)
    {
        if(i<n-2&&a[i]==a[i+1]&&a[i]==a[i+2])
        {
            continue;
        }
        else
        {
            a[j++]=a[i];
        }
    }

    printf("\nArray after removing duplicates(2 allowed): ");
    for(i=0;i<j;i++)
        printf("%d ",a[i]);
}
