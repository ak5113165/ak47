#include<iostream>
#include<stdio.h>
using namespace std;
void ankit(int arr[][3],int brr[][3],int n,int m,int i,int j)
{
    if(i>=n||j>=m||i<0||j<0)
    {
        return ;
    }
    if(arr[i][j]==0)
    {
        return;
    }
    if(brr[i][j]==0)
    {
        brr[i][j]=1;
        ankit(arr,brr,n,m,i+1,j);
        ankit(arr,brr,n,m,i-1,j);
        ankit(arr,brr,n,m,i,j+1);
        ankit(arr,brr,n,m,i,j-1);
        ankit(arr,brr,n,m,i+1,j+1);
        ankit(arr,brr,n,m,i-1,j-1);
        ankit(arr,brr,n,m,i+1,j-1);
        ankit(arr,brr,n,m,i-1,j+1);
    }
}
int main()
{
    int arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
   int brr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            brr[i][j]=0;
        }
    }
    int c=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==1&&brr[i][j]==0)
            {
                ankit(arr,brr,3,3,i,j);
                c++;
            }
        }
    }
    cout<<c;
     return 0;
}