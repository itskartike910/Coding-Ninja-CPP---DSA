#include <iostream>
#include <bits/stdc++.h>
// #include "solution.h"
using namespace std;

void reverseStringWordWise(char input[])
{
    // Write your code here
    int sp = strlen(input);
    char output[sp];
    int p = sp;
    int j = sp - 1;
    int i = 0;
    while (j >= 0 || j == -1) // Since the first word will not have any space before it So it wont count
    {
        if (input[j] == ' ' || j == -1)
        {
            for (int k = j + 1; k < p; k++) // j gets iterated from -1 to 0. Thus giving the frist word upto the the last space traced.
            {
                output[i++] = input[k];
            }
            p = j;
            j--;
            output[i++] = ' ';
        }
        else
        {
            j--;
        }
    }
    for (int l = 0; l < sp; l++)
    {
        input[l] = output[l];
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
