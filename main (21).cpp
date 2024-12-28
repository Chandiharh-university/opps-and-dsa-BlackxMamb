#include <iostream>
#include <vector>
using namespace std;

class NQueensSolver {
private:
    int solutions;
    bool isSafe(const vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
    
            if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
    void solveNQueens(vector<int>& board, int row, int n) {
        if (row == n) {
            solutions++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;      
                solveNQueens(board, row + 1, n); 
            
            }
        }
    }

public:
    NQueensSolver() : solutions(0) {}
    int totalNQueens(int n) {
        solutions = 0;                  
        vector<int> board(n, -1);        
        solveNQueens(board, 0, n);      
        return solutions;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    NQueensSolver solver;
    int result = solver.totalNQueens(n);
    cout << "The number of distinct solutions for " << n << "-Queens is: " << result << endl;

    return 0;
}
