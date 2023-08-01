#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int m,n;
    cin>>m>>n;
	int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int j=0;j<n;j++){
        int sumc=0;
        for(int i=0;i<m;i++){
            sumc+=arr[i][j];
        }
        cout<<sumc<<" ";
    }
    for(int i=0;i<m;i++){
        int sumr=0;
        for(int j=0;j<n;j++){
            sumr+=arr[i][j];
        }
        cout<<sumr<<" ";
    }
}
