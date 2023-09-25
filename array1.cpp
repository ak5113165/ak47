#include <iostream>
#include <stdio.h>
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
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int x = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        rotateclockwise(arr, n);
        for (int i = 0; i < n; i++)
        {
            sum += i * arr[i];
        }
        ans=max(ans,sum);
        sum=0;
    }
    cout << ans;
    ;
    return 0;
}