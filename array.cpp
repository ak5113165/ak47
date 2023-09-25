#include<bits/stdc++.h>
using namespace std;
void rotateclockwise(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}
void rotateanti(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
void alter(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void aside(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            for (int j = i; j < n; j++)
            {
                if (arr[j] > 0)
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void sorted(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (abs(arr[i]) >= abs(arr[j]))
        {
            swap(arr[i], arr[j]);
            j--;
        }
        else
            i++;
    }
}
int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 45, 76, 87, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    string s="aeiaaioaaaaeiiiiouuuooaauuaeiu";
    sort(s.begin(),s.end());
    cout<<s;
    rotateclockwise(arr, n);
    /*  rotateclockwise(arr,n);
    rotateclockwise(arr,n);
    rotateclockwise(arr,n);
    rotateanti(arr,n);
    rotateanti(arr,n);
    rotateanti(arr,n);*/
    //sorted(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    /*cout<<endl;
    aside(arr,n);
    cout<<endl;
    alter(arr,n);*/

    return 0;
}
