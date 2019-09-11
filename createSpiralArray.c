#include<stdio.h>
void createSpiral(int n)
{
    int a[n][n];
    int count=1,c1=0,r1=0,c2=n,r2=n,i=0,j=0;
    while(c1<=c2 && r1<=r2)
    {
        for(i=c1;i<c2;i++)
            a[r1][i]=count++;
        r1++;
        for(i=r1;i<r2;i++)
            a[i][c2-1]=count++;
        c2--;
        for(i=c2-1;i>=c1;i--)
            a[r2-1][i]=count++;
        r2--;
        for(i=r2-1;i>=r1;i--)
            a[i][c1]=count++;
        c1++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
                printf("%d\t",a[i][j]);
        }

        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter size of 2D array to create a spiral array: ");
    scanf("%d",&n);
    createSpiral(n);
}
