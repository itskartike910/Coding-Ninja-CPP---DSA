#include<bits/stdc++.h>
#include<climits>
using namespace std;
// #include"solution.h"

void Leaders(int arr[],int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
	for(int i=0;i<len;i++){
        int lead=arr[i],flag=0;
        for(int j=i+1;j<len;j++){
            if(arr[j]>lead){
                flag=0;
                break;
            }
            else{
                flag=1;
            }
        }
        if(flag==1) cout<<lead<<" ";
    }
    cout<<arr[len-1];
}

int main()
{
    int len;
    cin>>len;
	int arr[len];
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}