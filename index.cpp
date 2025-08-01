#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, (int)s.size()));

        int currentRow = 0;
        bool goingDown = false;

        
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};


void printZigZagPattern(string s, int numRows) {
    if (numRows == 1) {
        cout << s << endl;
        return;
    }

    vector<vector<char>> grid(numRows, vector<char>(s.length(), ' '));

    int currentRow = 0;
    bool goingDown = false;

    for (int i = 0; i < s.length(); i++) {
        grid[currentRow][i] = s[i];

        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }

        currentRow += goingDown ? 1 : -1;
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < s.length(); j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << "String original: " << s << endl;
    cout << "Número de linhas: " << numRows << endl << endl;

    cout << "Padrão ZigZag:" << endl;
    printZigZagPattern(s, numRows);

    cout << endl << "Resultado: " << solution.convert(s, numRows) << endl;

    cout << "\n--- Teste com 4 linhas ---" << endl;
    numRows = 4;
    cout << "Padrão ZigZag:" << endl;
    printZigZagPattern(s, numRows);
    cout << "Resultado: " << solution.convert(s, numRows) << endl;

    return 0;
}
