int comparator(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int find_pair(int arr[],int n,int x)
{
    int l=0,h=n-1;
    while(l<=h)
    {
       int mid=(l+h)/2;
       if(arr[mid]<x)
       l=mid+1;
       else if(arr[mid]>x)
       h=mid-1;
       else
       return mid;
    }
    return -1;
}
int countPairs(int numbers_count, int* numbers, int k) {
    int count=0;
    qsort(numbers,numbers_count,sizeof(numbers[0]),comparator);
    int j=0;
    for(int i=1;i<numbers_count;i++)
    {
     	if(numbers[i]!=numbers[j])
	{
            j++;
            numbers[j]=numbers[i];
      	}
    }
    int n=j+1;
   for(int i=0;i<n;i++)
   {
      if(find_pair(numbers,numbers_count,numbers[i]+k)!=-1)
      count++;
   }
   return count;
}