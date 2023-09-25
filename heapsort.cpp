#include<iostream>
#include<stdio.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if((l<n)&&(arr[l]<arr[smallest]))//for desecnding order just chnage the sign
    {
        smallest=l;
    }
    if((r<n)&&(arr[r]<arr[smallest]))//for desecnding order just chnage the sign
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,n,0);
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={12,11,56,87,98,23,45,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    print(arr,n);
}