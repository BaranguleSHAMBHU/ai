/*
Practical 4:
Aim: Implement a solution for Constraint Satisfaction Problem
using Backtracking and Branch & Bound for N-Queens Problem.
*/
/*
Sample Input:

Enter value of N: 4

Sample Output:

Solution for 4-Queens Problem:

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Chessboard Representation:

. . Q .
Q . . .
. . . Q
. Q . .
*/

#include <iostream>
#include <vector>
using namespace std;

class NQueens
{
private:
    int n;
    vector<vector<int>> board;

    // Arrays for Branch and Bound optimization
    vector<bool> rows;
    vector<bool> upperDiagonal;
    vector<bool> lowerDiagonal;

public:
    // Constructor
    NQueens(int size)
    {
        n = size;

        board = vector<vector<int>>(n, vector<int>(n, 0));

        rows = vector<bool>(n, false);
        upperDiagonal = vector<bool>(2 * n - 1, false);
        lowerDiagonal = vector<bool>(2 * n - 1, false);
    }

    // Function to solve N-Queens problem
    bool solveNQUtil(int col)
    {
        // Base Case: If all queens are placed
        if (col >= n)
        {
            return true;
        }

        // Try placing queen in all rows one by one
        for (int i = 0; i < n; i++)
        {
            /*
            Check if queen can be placed safely:
            1. Row should not be occupied
            2. Lower diagonal should not be occupied
            3. Upper diagonal should not be occupied
            */

            if (rows[i] == false &&
                lowerDiagonal[i + col] == false &&
                upperDiagonal[n - 1 + col - i] == false)
            {
                // Place the queen
                board[i][col] = 1;

                // Mark row and diagonals as occupied
                rows[i] = true;
                lowerDiagonal[i + col] = true;
                upperDiagonal[n - 1 + col - i] = true;

                // Recur to place rest of the queens
                if (solveNQUtil(col + 1))
                {
                    return true;
                }

                // BACKTRACKING
                // Remove queen if solution not found
                board[i][col] = 0;

                // Unmark row and diagonals
                rows[i] = false;
                lowerDiagonal[i + col] = false;
                upperDiagonal[n - 1 + col - i] = false;
            }
        }

        // If queen cannot be placed in any row
        return false;
    }

    // Function to print solution
    void printSolution()
    {
        if (solveNQUtil(0) == false)
        {
            cout << "Solution does not exist" << endl;
            return;
        }

        cout << "\nSolution for " << n << "-Queens Problem:\n\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nChessboard Representation:\n\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
};

// Driver Code
int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    NQueens queens(n);
    queens.printSolution();

    return 0;
}