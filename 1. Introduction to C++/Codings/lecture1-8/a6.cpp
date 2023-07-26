#include<bits/stdc++.h>
using namespace std;

int main(){
// 	string str;
// 	int cta=0,ctd=0,cts=0,i=0;
// 	while(cin>>str && str[i]!='$'){
// 		if((char)(str[i]) >=97 && (char)(str[i])<=122) cta++;
// 		else if((char)(str[i]) >=48 && (char)(str[i])<=57) ctd++;           //Wrong Approach
// 		else if((char)(str[i]) ==32) cts++;
//         i++;
// 	}
// 	cout<<cta<<" "<<ctd<<" "<<cts<<endl;
    char ch;
    int cta = 0, ctd = 0, cts = 0;
    while (cin.get(ch) && ch != '$') {
        if (ch >= 'a' && ch <= 'z') {
            cta++;
        } else if (ch >= '0' && ch <= '9') {
            ctd++;
        } else if (ch == ' ' || ch == '\t' || ch == '\n') {
            cts++;
        }
    }
    cout << cta << " " << ctd << " " << cts << endl;

}


