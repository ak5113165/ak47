#include<iostream>
#include<stdio.h>
using namespace std;
#define s 8
void merge(int ar[],int cr[],int n,int m)
{
    int a[s];
    int k=0;
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(ar[i]<=cr[j])
        {
            a[k]=ar[i];
            k++;
            i++;
        }
        else 
        {
            a[k]=cr[j];
            k++;
            j++;
        }
    }
    if(j>m-1)
    {
        a[k]=ar[i];
    }
    if(i>n-1)
    {
        a[k]=cr[j];
    }
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }
}
void insertion(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
       int key=arr[i];
       int j=i;
       while(arr[i-1]>key&&i>=1)
       {
           arr[i]=arr[i-1];
           i--;
       }
       arr[i]=key;
   }
   for(int i=0;i<s;i++)
   {
       cout<<arr[i]<<" ";
   }
}
void bublesort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
// selection sort
void select(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[min])
            {
                min=i;
            }
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={2,4,3,6,8,97,1,67,45};
    int crr[]={4,2,1,43,57,91,45,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        for(int i=i+1;i<n;i++)
        {
            if(arr[i]>arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
    int ar[]={2,3,6,9};
    int cr[]={1,4,5,7};
    
    int q=sizeof(ar)/sizeof(ar[0]);
    cout<<endl;
    bublesort(arr,n);
    cout<<endl;
    select(arr,n);
    cout<<endl;
    insertion(crr,n);
    cout<<endl;
    merge(ar,cr,q,q);
    
}