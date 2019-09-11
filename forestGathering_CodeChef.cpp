
#include <iostream>
using namespace std;
int fg(int n,int y,int *a,long long m,long long w,long long l)
{
    long long s=0;
    for(int i=0;i<n;i++)
    {
        if(*((a+i*2)+0)+*((a+i*2)+1)*m>=l)
        {    s+=*((a+i*2)+0)+*((a+i*2)+1)*m;
            if(s>=w)
                return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    long long w,ln;
    cin>>w;
    cin>>ln;
    int a[n][2];
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];
    long long l,r,m;
    int p;
    l=0;
    r=1000000000000000000;
    while(l<r)
    {
        m=(l+r)/2;
        p=fg(n,2,(int*)a,m,w,ln);
        if(p==1)
            r=m;
        else
            l=m+1;
    }
    cout<<l;
	// your code goes here
	return 0;
}
