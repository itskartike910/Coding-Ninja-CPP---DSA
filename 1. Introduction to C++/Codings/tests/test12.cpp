#include<iostream>
using namespace std;

int main(){
  // Write your code here
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
        cout<<j;
    }
    for(int j=2;j<=i;j++){
        cout<<"**";
    }
    for(int j=n-i+1;j>=1;j--){
        cout<<j;
    }
    cout<<endl;
  }
}