using namespace std;
#include<iostream>
#define max 5
template<typename T>
class stack
{
    T arr[max];
    int top;
    public:
void push()
{
    T d;
    cin>>d;
    arr[top]=2*d;
    top++;
}
void pop()
{
    T d;
    d=arr[top-1];
    top--;
}
void show()
{
    for(int i=0;i<top;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
};





int main()
{
     
     stack <int> s1;
     s1.push();
     s1.push();
     s1.push();
     s1.push();
     s1.push();
     s1.pop();
     s1.show();
     stack <float> s2;
     s2.push();
     s2.push();
     s2.push();
     s2.push();
     s2.push();
     s2.pop();
     s2.show();
     return 0;
     }
