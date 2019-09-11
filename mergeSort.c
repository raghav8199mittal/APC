#include<stdio.h>
void merge(int* a,int l,int m,int r,int* b)
{
    int i=l;
    int j=m,k=0;
    for(k=l;k<=r;k++)
    {
        if(j>r||i>=m)
            break;
        else if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }

    }
    while(i<m)
    {
        b[k++]=a[i];
        i++;
    }
    while(j<=r)
    {
        b[k++]=a[j];
        j++;
    }
    //printf("%d %d %d   ",l,m,r);
    //for(k=l;k<=r;k++)
    //    printf("%d ",b[k]);
    //printf("\n");
    for(k=l;k<=r;k++)
        a[k]=b[k];

}
void divide(int* a,int l,int r,int* b)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        divide(a,l,m,b);
        divide(a,m+1,r,b);
        merge(a,l,m+1,r,b);
    }
}
int main()
{
       int n,i;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        int l=0;int r=n-1;
        divide(a,l,r,b);
         printf("Array after sorting: \n");
        for(i=0;i<n;i++)
        printf("%d ",b[i]);

}
