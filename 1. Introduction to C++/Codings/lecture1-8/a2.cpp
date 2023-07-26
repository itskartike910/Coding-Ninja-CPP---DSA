#include<iostream>
using namespace std;


int main() {
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin>>n;
    if(n%2!=0){
        for(int i=1;i<=n/2+1;i++){
            for(int k=n/2;k>=i;k--){
                cout<<" ";
            }
            for(int j=1;j<=2*i-1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        for(int i=1;i<=n/2;i++){
            for(int k=1;k<=i;k++){
                cout<<" ";
            }
            for(int j=n;j>=2*i+1;j--){
                cout<<"*";
            }
            cout<<endl;
        }
    }
}
