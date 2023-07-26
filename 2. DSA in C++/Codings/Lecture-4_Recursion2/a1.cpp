#include <iostream>
// #include "solution.h"
using namespace std;

bool checkAB(char input[], int index = 0){
    // Write your code here
    if (input[0] == 'b' || input[0] == '\0')    return false;
    if (input[index + 1] == '\0')    return true;
    if (input[index + 1] == 'a')    return checkAB(input, index + 1);
    if (input[index + 1] == 'b' && input[index + 2] == 'b'){
        if (input[index + 3] == '\0')   return true;
        if (input[index + 3] == 'a')    return checkAB(input, index + 3);
        return false;
    }
    return false;
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)  cout << "true" << endl;
    else  cout << "false" << endl;
    return 0;
}
