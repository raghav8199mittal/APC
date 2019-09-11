#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
struct Interval
{
    int st,endd;
    Interval(){}
    Interval(int s,int v)
    {
        st=s;
        endd=v;
    }
};
int cmp(const void* a,const void* b)
{
    return ((struct Interval*)a)->st-((struct Interval*)b)->st;
}
int main()
{
    cout<<"Enter no. of total intervals: ";
    int n,i;
    cin>>n;
    struct Interval intv[n];
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter "<<i+1<<" interval: ";
        cin>>intv[i].st;
        cin>>intv[i].endd;
    }
    qsort(intv,n,sizeof(intv[0]),cmp);

    vector<Interval> v;
    for(i=0;i<n;i++)
        v.push_back(intv[i]);
    vector<Interval> vr;
    int v_st=v[0].st,v_end=v[0].endd;
    if(v.size()==1)
    {
        struct Interval I;
        I.st=v_st;
        I.endd=v_end;
        vr.push_back(I);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(v[i].st<=v_end)
            {
             struct Interval I(v_st,v[i].endd>=v_end?v[i].endd:v_end);
             v_end=v[i].endd>=v_end?v[i].endd:v_end;
             if(vr.size()==0)
             {
                 vr.push_back(I);
             }
             else if(I.st!=vr[vr.size()-1].st||I.endd!=vr[vr.size()-1].endd)
             {
                 if(I.st==vr[vr.size()-1].st)
                 {
                     vr[vr.size()-1].endd=I.endd;
                 }
                 else
                 {
                     vr.push_back(I);
                 }
             }
            }
            else
            {
                struct Interval I(v[i].st,v[i].endd);
                vr.push_back(I);
                v_st=vr[vr.size()-1].st;
                v_end=vr[vr.size()-1].endd;
            }
        }
    }
    for(i=0;i<vr.size();i++)
        cout<<vr[i].st<<" "<<vr[i].endd<<"\n";
}
