#include <iostream>
#include <vector>
using namespace std;

// #include "solution.h"

bool hasPath(vector<vector<char>> &board, int n, int m){
    // Write your code here.
    
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}