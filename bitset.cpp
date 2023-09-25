#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=10;
    for(int i=0;i<32;i++)
    {
        if((x&(1<<i))!=0)
        {
            cout<<i;
        }
    }
    cout<<endl;
    for(int i=31;i>=0;i--)
    {
        if((x&(1<<i))!=0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    cout<<endl;
    double X=235/2;
    cout<<ceil(X);
    return 0;
}