#include<stdio.h>
void convertMatrix(int r,int c,int a[r][c])
{
    int r1=1,c1=1,i,j;
    for(i=0;i<c;i++)
        r1=r1&a[0][i];
    for(i=0;i<r;i++)
        c1=c1&a[i][0];
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(a[i][j]==0)
            {
                a[0][j]=0;
                a[i][0]=0;
            }
        }
    }
    for(i=1;i<c;i++)
    {
        if(a[0][i]==0)
            for(j=1;j<r;j++)
                a[j][i]=0;
    }
    for(i=1;i<r;i++)
    {
        if(a[i][0]==0)
            for(j=1;j<c;j++)
                a[i][j]=0;
    }
    if(r1==0)
        for(i=0;i<c;i++)
            a[0][i]=0;
    if(c1==0)
        for(i=0;i<r;i++)
            a[i][0]=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int main()
{
    //Solution is considered using a constraint i.e the matrix is binary matrix with 0's and 1's only
    int r,c,i,j;
    printf("Enter no. of rows and columns: ");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("\nEnter elements of matrix in 0's and 1's only: \n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    printf("\nMatrix after converting: \n");
    convertMatrix(r,c,a);
}
