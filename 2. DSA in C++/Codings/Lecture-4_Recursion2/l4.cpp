#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// #include "solution.h"

class Runner
{
    vector<int> v;

public:
    void swap(int *arr, int a, int b)
    {
        int temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void quickSort(int arr[], int left, int right)
    {
        /*
            Don't write main().
            Don't read input, it is passed as function argument.
            Change in the given array itself.
            Taking input and printing output is handled automatically.
        */
        int i = left, j = right, pivot = arr[(left + right) / 2];
        while (i <= j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j)
            {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        if (left < j)
            quickSort(arr, left, j);
        if (i < right)
            quickSort(arr, i, right);
    }

    void takeInput()
    {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute()
    {
        int n = (int)v.size();

        int *input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        free(input);
    }

    void executeAndPrintOutput()
    {
        int n = (int)v.size();

        int *input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << input[i] << ' ';
        cout << '\n';

        free(input);
    }
};

int main()
{
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}