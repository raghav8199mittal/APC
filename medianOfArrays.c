#include<stdio.h>
#include<limits.h>
//assume array a and b are sorted
//Optimized solution by Binary Search
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
int main()
{
    int n,i,j,m,l=0,ans;
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
    b[-1]=INT_MIN;
    a[n]=INT_MAX;
    a[-1]=INT_MIN;
    b[m]=INT_MAX;
    int k=n+m;
    int l1=0,l2,r1=n-1,r2,m1,m2;
    while(l1<=r1)
    {
        m1=(r1+l1)/2;
        m2=k/2-(m1+1)-1;
        //printf("  %d %d  ",m1,m2);
        if(a[m1]<=b[m2+1]&&b[m2]<=a[m1+1])
            break;
        else if(a[m1]>b[m2+1])
            r1=m1;
        else
            l1=m1+1;
    }

    if(k%2==0)
        ans=(MAX(a[m1],b[m2])+MIN(a[m1+1],b[m2+1]))/2;
    else
        ans=MIN(a[m1+1],b[m2+1]);
    printf("\nMedian: %d %d %d",ans,m1,m2);
}
