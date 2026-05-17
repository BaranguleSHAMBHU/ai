'''
Practical:- 4
Aim: Implement a solution for Constraint Satisfaction Problem
using Backtracking and Branch & Bound for N-Queens Problem

Python Program for N-Queens Problem using Branch and Bound

'''
class NQueens:
    def __init__(self, n):
        self.n = n

        # Create chessboard initialized with 0
        self.board = [[0 for _ in range(n)] for _ in range(n)]

        # Arrays for Branch and Bound optimization
        self.rows = [False] * n
        self.upperDiagonal = [False] * (2 * n - 1)
        self.lowerDiagonal = [False] * (2 * n - 1)

    # Function to solve N-Queens problem
    def solveNQUtil(self, col):

        # Base Case: If all queens are placed
        if col >= self.n:
            return True

        # Try placing queen in all rows one by one
        for i in range(self.n):

            # Check if queen can be placed safely
            if (self.rows[i] == False and
                self.lowerDiagonal[i + col] == False and
                self.upperDiagonal[self.n - 1 + col - i] == False):

                # Place the queen
                self.board[i][col] = 1

                # Mark row and diagonals as occupied
                self.rows[i] = True
                self.lowerDiagonal[i + col] = True
                self.upperDiagonal[self.n - 1 + col - i] = True

                # Recur to place rest of the queens
                if self.solveNQUtil(col + 1):
                    return True

                # BACKTRACKING
                # Remove queen if solution not found
                self.board[i][col] = 0

                # Unmark row and diagonals
                self.rows[i] = False
                self.lowerDiagonal[i + col] = False
                self.upperDiagonal[self.n - 1 + col - i] = False

        # If queen cannot be placed in any row
        return False

    # Function to print solution
    def printSolution(self):

        if self.solveNQUtil(0) == False:
            print("Solution does not exist")
            return

        print(f"\nSolution for {self.n}-Queens Problem:\n")

        for i in range(self.n):
            for j in range(self.n):
                print(self.board[i][j], end=" ")
            print()

        print("\nChessboard Representation:\n")

        for i in range(self.n):
            for j in range(self.n):
                if self.board[i][j] == 1:
                    print("Q", end=" ")
                else:
                    print(".", end=" ")
            print()


# Driver Code
if __name__ == "__main__":

    n = int(input("Enter value of N: "))

    queens = NQueens(n)
    queens.printSolution()

'''

Enter value of N: 4

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


'''
