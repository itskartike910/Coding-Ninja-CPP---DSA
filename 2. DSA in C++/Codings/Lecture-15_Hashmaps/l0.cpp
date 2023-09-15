#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int *a, int size){
    vector<int> output;            
    unordered_map<int, bool> seen; 
    for (int i = 0; i < size; i++){ 
        if (seen.count(a[i]) > 0){             
            continue; 
        }
        seen[a[i]] = true;      
        output.push_back(a[i]); 
    }
    return output;
}

int main(){
    int a[]={1,2,8,9,2,0,5,1,3,1};
    vector<int> vec = removeDuplicates(a,10);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}