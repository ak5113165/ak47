#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int maxdistance(int arr[],int n)
{
    unordered_map<int,int> mp;
    int maxe=0;
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr[i])==mp.end())
        {
        mp[arr[i]]=i;
        }
        else
        maxe=max(maxe,i-mp[arr[i]]);
    }
    return maxe;
}
int rachana(int arr[],int n)
{
    unordered_map<int,int> sa;
    for(int i=0;i<n;i++)
    {
        sa[arr[i]]++;
    }
    int maxe=INT_MIN;
    for(auto it=sa.begin();it!=sa.end();it++)
    {
       maxe=max(maxe,it->second);
    }
    return n-maxe;
}
void ankit(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]=i;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"  "<<it->second;
        cout<<endl;
    }
}
void sahil(int arr[],int n,int x)
{
    unordered_map<int,int> ma;
    for(int i=0;i<n;i++)
    {
        if(ma.find(x-arr[i])!=ma.end())
        {
        cout<<arr[i];
        cout<<endl;
        cout<<x-arr[i];
        cout<<endl;
        cout<<ma[x-arr[i]];
;        }
        ma[arr[i]]=i;
    }

}
int main()
{
    int arr[]={4,2,3,4,4,5,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
   // cout<<maxdistance(arr,n);
    cout<<endl;
    //ankit(arr,n);
    //sahil(arr,n,16);
   cout<<rachana(arr,n);
        return 0;
}