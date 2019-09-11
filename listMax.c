int main()
{
int n,i,m=0,count=0,max_count=0,max_count_no=0;
printf("Enter size of list ");
scanf("%d",&n);
int l[n],r[n];
printf("\nEnter left list ");
for(i=0;i<n;i++)
scanf("%d",&l[i]);
printf("\nEnter right list ");
for(i=0;i<n;i++)
scanf("%d",&r[i]);
m=r[0];
for(i=0;i<n;i++)
if(r[i]>m)
m=r[i];
m+=2;
int cn[m];
for(i=0;i<m;i++)
        cn[i]=0;
for(i=0;i<n;i++)
{
cn[l[i]]+=1;
cn[r[i]+1]-=1;
}
max_count=cn[0];
for(i=0;i<m;i++)
{
count+=cn[i];

printf("%d ",count);
if(max_count<count)
{
max_count=count;
max_count_no=i;
}
}
printf("\nMaximum times occured element is : %d",max_count_no);
}
