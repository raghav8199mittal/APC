#include<stdio.h>
 int main()
     {
     int n,i,j;
     printf("Enter the length of array:");
     scanf("%d",&n);
     int a[n];
     printf("\nEnter %d elements:",n);
     for(i=0;i<n;i++)
         scanf("%d",&a[i]);
     int k;
     printf("\nEnter size of each group:");
     scanf("%d",&k);
     int k1=k;
     for(i=0;i<n;i+=k)
     {
         if(i+k>n)
         k1=n-i;
         for(j=0;j<k1/2;j++)
         {
             int temp=a[i+j];
             a[i+j]=a[i+k1-j-1];
             a[i+k1-j-1]=temp;
         }
     }
      printf("\nArray after reversing in group of length %d\n",k);
     for(i=0;i<n;i++)
     {
        printf("%d ",a[i]);
     }
     return 0;
     }
