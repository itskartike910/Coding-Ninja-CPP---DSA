#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
	int n,k=0,j=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int l=n-1;l>=i;l--){
			cout<<" ";
		}
		for(j;j<=i && k<2*n;j++){
            for(k=i;k<2*j;k++){
                cout<<k;
            }
		}
		cout<<endl;
	}
  
}


