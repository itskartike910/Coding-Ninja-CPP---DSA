#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 10;
char crossword[N][N];

bool canPlaceWordHorizontally(int r, int c, string word) {
    int len = word.length();
    if (c + len > N) return false;
    for (int i = 0; i < len; i++) {
        if (crossword[r][c + i] != '-' && crossword[r][c + i] != word[i]) {
            return false;
        }
    }
    return true;
}

bool canPlaceWordVertically(int r, int c, string word) {
    int len = word.length();
    if (r + len > N) return false;
    for (int i = 0; i < len; i++) {
        if (crossword[r + i][c] != '-' && crossword[r + i][c] != word[i]) {
            return false;
        }
    }
    return true;
}

void placeWordHorizontally(int r, int c, string word) {
    int len = word.length();
    for (int i = 0; i < len; i++) {
        crossword[r][c + i] = word[i];
    }
}

void placeWordVertically(int r, int c, string word) {
    int len = word.length();
    for (int i = 0; i < len; i++) {
        crossword[r + i][c] = word[i];
    }
}

void printCrossword() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << crossword[i][j];
        }
        cout << endl;
    }
}

bool crosswordSolver(vector<string>& words, int wordIndex) {
    if (wordIndex == words.size()) {
        // All words have been placed
        return true;
    }

    string word = words[wordIndex];
    int len = word.length();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (crossword[i][j] == '-' || crossword[i][j] == word[0]) {
                if (canPlaceWordHorizontally(i, j, word)) {
                    vector<vector<char>> backup(N, vector<char>(N)); // Create a backup vector
                    for (int k = 0; k < N; k++) {
                        for (int l = 0; l < N; l++) {
                            backup[k][l] = crossword[k][l];
                        }
                    }
                    placeWordHorizontally(i, j, word);
                    if (crosswordSolver(words, wordIndex + 1)) {
                        return true;
                    }
                    // Restore the crossword grid from the backup
                    for (int k = 0; k < N; k++) {
                        for (int l = 0; l < N; l++) {
                            crossword[k][l] = backup[k][l];
                        }
                    }
                }
                if (canPlaceWordVertically(i, j, word)) {
                    vector<vector<char>> backup(N, vector<char>(N)); // Create a backup vector
                    for (int k = 0; k < N; k++) {
                        for (int l = 0; l < N; l++) {
                            backup[k][l] = crossword[k][l];
                        }
                    }
                    placeWordVertically(i, j, word);
                    if (crosswordSolver(words, wordIndex + 1)) {
                        return true;
                    }
                    // Restore the crossword grid from the backup
                    for (int k = 0; k < N; k++) {
                        for (int l = 0; l < N; l++) {
                            crossword[k][l] = backup[k][l];
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> crossword[i][j];
        }
    }

    string wordsList;
    cin.ignore(); // Clear the newline character
    getline(cin, wordsList);

    vector<string> words;
    string word;
    for (char c : wordsList) {
        if (c == ';') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    crosswordSolver(words, 0);
    printCrossword();

    return 0;
}