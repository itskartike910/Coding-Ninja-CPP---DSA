#include <iostream>
using namespace std;
#include <climits>

int main()
{
    // Write your code here
    int n;
    cin >> n;

    int large = INT_MIN;
    int seclarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > large)
        {
            seclarge = large;
            large = x;
        }
        else if (x > seclarge && x != large)
        {
            seclarge = x;
        }
    }

    if (n < 2)
    {
        seclarge = INT_MIN;
    }
    cout << seclarge << endl;
}
