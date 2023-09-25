#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
int main()
{
    int arr[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                swap(arr[i][j], arr[j][i]); //swap(arr[i][i+1],arr[i+1][i])
            }
            else
            {

                break;
            }
        }
    }
    // swap(arr[0][1], arr[1][0]);
    // swap(arr[0][2], arr[2][0]);
    // swap(arr[2][1], arr[1][2]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    for (int j = 3; j >= 0; j--)
    {
        for (int i = 0; i < 4; i++)
        {
            
        }

    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
