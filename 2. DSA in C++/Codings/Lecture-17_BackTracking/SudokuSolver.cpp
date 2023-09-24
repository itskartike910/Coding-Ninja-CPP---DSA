#include<bits/stdc++.h>
using namespace std;

bool findEmptyLocation(vector<vector<int>> &grid, int &row, int &col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isValid(vector<vector<int>> &grid, int row, int col, int n) {
    // Checking for column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == n) {
            return false;
        }
    }
    // Checking for row
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == n) {
            return false;
        }
    }
    // Checking for box
    int rowFact = row - (row % 3); // Row Factor
    int colFact = col - (col % 3); // Col Factor
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + rowFact][j + colFact] == n) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &grid) {
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        return true; // Finding Empty Location -> if not found return true;
    }

    // Try filling the cell with numbers from 1 to 9
    for (int i = 1; i <= 9; i++) {
        if (isValid(grid, row, col, i)) {
            grid[row][col] = i; // Suited for number i
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0; // If not a solution, backtrack and try the next number
        }
    }

    return false; // Cannot be solved
}

int main() {
    // Write your code here
    vector<vector<int>> grid(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }
    if (solveSudoku(grid)) {
        cout << "true" << endl;
        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    } else {
        cout << "false" << endl;
    }
    return 0;
}
