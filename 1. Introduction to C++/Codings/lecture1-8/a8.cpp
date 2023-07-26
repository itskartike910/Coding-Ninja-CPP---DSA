#include <iostream>
using namespace std;

bool canSplitSequence(int arr[], int n)
{
    int i = 0;

    while (i < n - 1 && arr[i] > arr[i + 1])
    {
        i++;
    }

    while (i < n - 1 && arr[i] < arr[i + 1])
    {
        i++;
    }

    return i == n - 1;
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
    if (canSplitSequence(arr, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
