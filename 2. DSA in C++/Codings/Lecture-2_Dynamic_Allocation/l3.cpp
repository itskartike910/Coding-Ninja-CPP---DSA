//Inline functions and default arguments;
#include <bits/stdc++.h>
using namespace std;

//default argument    --> Always give default value from the right-most argument;
int sum(int arr[],int size,int si=0 /*Default Argument*/){
    int ans=0;
    for(int i=si;i<size;i++){
        ans+=arr[i];
    }
    return ans;
}

//Inline fuction
inline int max(int a,int b){
    return (a>b) ? a : b;
}


int main(){

    // int a,b;
    // cin>>a>>b;
    // // cout<<((a>b) ? a : b )<<endl;
    // int c = max(a,b);
    // cout<<c<<endl;
}