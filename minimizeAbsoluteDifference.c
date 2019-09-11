/*Minimize the absolute difference.
Array a,b,c with size n,m,l are given in sorted order.
return minimum value of abs(max(a[i],b[j],c[k])-min(a[i],b[j],c[k]))*/

#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b,c) ((a<b&&a<c)?a:(b<c?b:c))
#define MAX(a,b,c) ((a>b&&a>c)?a:(b>c?b:c))
int* minAbsDiff(int n,int m,int l,int a[n],int b[m],int c[l])
{
    int i=0,j=0,k=0,minA[4],min1;
    minA[0]=abs(MAX(a[0],b[0],c[0])-MIN(a[0],b[0],c[0]));
    minA[1]=a[0];
    minA[2]=b[0];
    minA[3]=c[0];
    //for(i=0;i<4;i++)
    //    printf("%d  ",minA[i]);
    while(i<n&&j<m&&k<l)
    {
        if(abs(MAX(a[i],b[j],c[k])-MIN(a[i],b[j],c[k]))<minA[0])
            {
                minA[0]=abs(MAX(a[i],b[j],c[k])-MIN(a[i],b[j],c[k]));
                minA[1]=a[i];
                minA[2]=b[j];
                minA[3]=c[k];
            }
        min1=MIN(a[i],b[j],c[k]);
        if(a[i]==min1)
            i++;
        else if(b[j]==min1)
            j++;
        else
            k++;
    }
    return minA;
}
int main()
{
    int n,m,l,i;
    printf("Enter size of array a: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements of array a in sorted order: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter size of array b: ");
    scanf("%d",&m);
    int b[m];
    printf("\nEnter elements of array b in sorted order: ");
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        printf("\nEnter size of array c: ");
    scanf("%d",&l);
    int c[l];
    printf("\nEnter elements of array c in sorted order: ");
    for(i=0;i<l;i++)
        scanf("%d",&c[i]);
        int *minA=minAbsDiff(n,m,l,a,b,c);
    printf("\nMinimum Absolute Difference is : %d and the combination is %d,%d,%d",minA[0],minA[1],minA[2],minA[3]);
}
