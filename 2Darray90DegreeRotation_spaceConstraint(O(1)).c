#include<stdio.h>
void printArray(int n,int a[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the size of 2D array: ");
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    printf("\nEnter elements of 2D array of size %d\n",n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Array after 90 degree rotation: \n");
    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-1-i;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[n-1-j][i];
            a[n-1-j][i]=a[n-1-i][n-1-j];
            a[n-1-i][n-1-j]=a[j][n-1-i];
            a[j][n-1-i]=temp;
        }
    }
    printArray(n,a);
}
