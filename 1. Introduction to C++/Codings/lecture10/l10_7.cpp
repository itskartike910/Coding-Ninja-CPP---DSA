#include <iostream>
using namespace std;

// #include "solution.h"
/*
You can use minimum value of integer as -2147483647 and
maximum value of integer as 2147483647
*/
void findLargest(int **input, int nRows, int mCols)
{
    // Write your code here
    int min = -2147483648;
    if (nRows == 0 && mCols == 0)
    {
        cout << "row " << 0 << " " << min;
    }
    else
    {
        int *arrc = new int[mCols];
        for (int j = 0; j < mCols; j++)
        {
            int sumc = 0;
            for (int i = 0; i < nRows; i++)
            {
                sumc += input[i][j];
            }
            // cout<<sumc<<" ";
            arrc[j] = sumc;
        }
        // cout<<endl;
        int *arrr = new int[nRows];
        for (int i = 0; i < nRows; i++)
        {
            int sumr = 0;
            for (int j = 0; j < mCols; j++)
            {
                sumr += input[i][j];
            }
            // cout<<sumr<<" ";
            arrr[i] = sumr;
        }
        int maxc = arrc[0], maxr = arrr[0], rowno = 0, colno = 0;
        for (int i = 0; i < mCols; i++)
        {
            if (maxc < arrc[i])
            {
                maxc = arrc[i];
                colno = i;
            }
        }
        for (int i = 0; i < nRows; i++)
        {
            if (maxr < arrr[i])
            {
                maxr = arrr[i];
                rowno = i;
            }
        }
        if (maxc > maxr)
            cout << "column " << colno << " " << maxc;
        else if (maxc <= maxr)
            cout << "row " << rowno << " " << maxr;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}