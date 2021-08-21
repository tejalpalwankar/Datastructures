#include <iostream>
using namespace std;

int mincost(int n, int arr[])
{
    int i,j,cost = 0;
    for (j =0; j < n; j++)
    {
        for (i = 0; i < n - i; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cost =cost +  (arr[i] - arr[i + 1]);
                // cout << cost << endl;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    return cost;
}

int main()
{
    int input[] = {7, 4, 6, 5, 8};
    // int input[] = {1,2,3};
    int cost = mincost(5, input);
    cout << cost << endl;
}