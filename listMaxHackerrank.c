long listMax(int n, int operations_rows, int operations_columns, int** operations) {
    long *a=(long*)malloc((n+2)*sizeof(long));
    //long a[n+2];
    int i,n1=n+2;
    for(i=0;i<n1;i++)
        a[i]=0;
    for(i=0;i<operations_rows;i++)
    {
        /*if(operations[i][0]<0)
            operations[i][0]=0;
        if(operations[i][1]<0)
            operations[i][1]=0;
        if(operations[i][0]>n)
            operations[i][0]=n;
        if(operations[i][1]>n)
            operations[i][1]=n;*/
        
        a[operations[i][0]]+=operations[i][2];
        a[operations[i][1]+1]-=operations[i][2];
    }
    long max=a[0],m=a[0];
    for(i=0;i<n1;i++)
        printf("%d ",a[i]);
    for(i=1;i<n1-1;i++)
    {
        m+=a[i];
        if(m>max)
            max=m;
    }
    return max;
    
}