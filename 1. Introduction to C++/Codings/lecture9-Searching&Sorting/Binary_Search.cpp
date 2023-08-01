//Binary Search
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Runner
{
    int t = 1;

    vector<int> v;
    int x;

public:
    void takeInput()
    {
        int n;
        cin >> n;
        assert(1 <= n && n <= (int)1e4);
        v.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        cin >> x;
    }
    int search(vector<int> &nums, int target)
    {
        // Write Your Code Here
        int low = 0, high = nums.size(), mid, flag = 0;
        while (low <= high)
        {

            mid = (low + high) / 2;
            if (target == nums[mid])
            {
                flag = 1;
                return mid;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
        }
        if (flag == 0)
        {
            return -1;
        }
        return 0;
    }
    void execute()
    {
        vector<int> copy = v;
        search(copy, x);
    }

    void executeAndPrintOutput()
    {
        vector<int> copy = v;
        int ans = search(copy, x);
        cout << ans << '\n';
    }
};

int main()
{
    // freopen("./Testcases/large/in/input11.txt", "r", stdin);
    // freopen("./Testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
