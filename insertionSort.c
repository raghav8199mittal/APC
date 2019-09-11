#include<stdio.h>
void insertionSort(int *a,int n)
{
    int key,j,i;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
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
    insertionSort(a,n);
    printf("Array after sorting: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
