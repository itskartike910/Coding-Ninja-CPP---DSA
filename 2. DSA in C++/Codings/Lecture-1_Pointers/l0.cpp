#include <bits/stdc++.h>
using namespace std;

// void square(int *p)
// {
//     int a = 10;
//     p = &a;
//     *p = (*p) * (*p);
// }

int main()
{
    // float f = 10.5;
    // float p = 2.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p;

    // int a[] = {1, 2, 3, 4};
    // int *p = a++;
    // cout << *p << endl;

    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout << *ptr << endl;

    // int a = 10;
    // square(&a);
    // cout << a << endl;

    //     int a = 10;
    //     int *p = &a;
    //     int **q = &p;
    //     int b = 20;
    //     *q = &b;
    //     (*p)++;
    //     cout << a << " " << b << endl;

    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++;
    int *r = *q;
    (*r)++;
    cout << a << " " << b << endl;
}