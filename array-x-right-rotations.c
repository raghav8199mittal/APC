#include <stdio.h>

void rotatebyOne(int arr[], int n);

void rotate(int arr[], int d, int n)
{
    int i;
    for (i = 0; i < d; i++)
        rotatebyOne(arr, n);
}

void rotatebyOne(int arr[], int n)
{
    int temp = arr[n-1], i;
    for (i = n-1; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] = temp;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}

int main()
{
    int n,i;
    printf("Enter no. elements in array ");
    scanf("%d",&n);
    printf("\nEnter elements ");
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter no. of rotations to be performed in right direction: ");
    int d;
    scanf("%d",&d);
    printf("\nArray after %d rotations: ",d);
    rotate(arr,d%n,n);
    printArray(arr,n);
    return 0;
}
