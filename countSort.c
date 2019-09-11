#include<stdio.h>
void countSort(int* a,int n)
{
    int i;
    int a_new[n];
    int m=a[0];
    for(i=0;i<n;i++)
        if(a[i]>m)
            m=a[i];
        m++;
    int b[m];
    for(i=0;i<m;i++)
        b[i]=0;
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(i=1;i<m;i++)
        b[i]+=b[i-1];
    int j=0;
    for(i=0;i<n;i++)
    {
        a_new[b[a[i]]-1]=a[i];
        b[i]--;
    }
    for(i=0;i<n;i++)
        a[i]=a_new[i];
}

int main()
{
    int n,i;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    countSort(a,n);
    printf("Array after sorting: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
