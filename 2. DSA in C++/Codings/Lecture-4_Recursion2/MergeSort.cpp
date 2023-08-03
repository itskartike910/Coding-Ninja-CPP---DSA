#include <bits/stdc++.h>

using namespace std;
// #include "solution.h"

class Runner
{
    vector<int> v;

public:
    void Merge(vector<int> &A,int low,int mid,int high){
	int i,j,k,t[high-low+1],n=high-low+1;
	for(i=0,j=low,k=mid+1;j<=mid && k<=high; ){
		if (A[j]<=A[k]){
			t[i++]=A[j++];
		}
		else{
			t[i++]=A[k++];
		}
	}
	while(j<=mid){
		t[i++]=A[j++];
	}
	while(k<=high){
		t[i++]=A[k++];
	}
	i=0;
	j=low;
	while(i<n){
		A[j++]=t[i++];
	}
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        // Write Your Code Here
        if (l >= r)
            return;
        else
        {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            Merge(arr, l, mid, r);
        }
    }

    void takeInput()
    {
        int n;
        cin >> n;
        v.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
    }

    void execute()
    {
        auto c = v;
        mergeSort(c, 0, (int)c.size() - 1);
    }

    void executeAndPrintOutput()
    {
        auto c = v;
        mergeSort(c, 0, (int)c.size() - 1);
        for (int i = 0; i < c.size(); ++i)
            cout << c[i] << ' ';
        cout << endl;
    }
};

int main()
{
    // freopen("./Testcases/large/in/input30.txt", "r", stdin);
    // freopen("./Testcases/large/out/output30.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
