#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // Include for tolower function
using namespace std;
bool searchCharacter(vector<vector<char>>& matrix, char target, int& row, int& col) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (tolower(matrix[i][j]) == tolower(target)) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool checkWordInMatrix(vector<vector<char>>& matrix, string& word) {

    int currentRow = 0, currentCol = 0;

    for (char ch : word) {
        if (!searchCharacter(matrix, ch, currentRow, currentCol)) {
            return false;  // Character not found in matrix
        }
    }

    return true;  // All characters found in the matrix
}

int main() {
    vector<vector<char>> matrix = {
        {'D', 'F', 'G', 'T', 'H'},
        {'B', 'F', 'H', 'J', 'H'},
        {'M', 'A', 'K', 'G', 'K'}
    };

    vector<string> words = {"MAT", "BAT", "CAT"};

    for ( string& word : words) {
        bool found = checkWordInMatrix(matrix, word);
        cout << "Word '" << word << "' found: " << (found ? "Yes" : "No") << endl;
    }
    return 0;
}
