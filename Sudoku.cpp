#include "Sudoku.h"
#include <iostream>
#include <vector>

using namespace std;

Sudoku::Sudoku() : board(9, vector<int>(9, 0)) {
    choice = true;
}

void Sudoku::print() {
    cout << "  1 2 3   4 5 6   7 8 9" << endl;
    cout << "  ---------------------" << endl;
    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row != 0) {
            cout << "  ------+-------+------" << endl;
        }
        cout << row + 1 << " ";
        for (int column = 0; column < 9; column++) {
            if (column % 3 == 0 && column != 0) {
                cout << "| ";
            }
            if (board[row][column] == 0) {
                cout << ". ";
            } else {
                cout << board[row][column] << " ";
            }
        }
        cout << endl;
    }
    cout << "  ---------------------" << endl;
}

void Sudoku::inputNumbers() {
    while (choice) {
        int n, m, number, input;
        cout << "Enter row (1-9) and column (1-9) to place a number, or 0 0 to stop: ";
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        if (n < 1 || n > 9 || m < 1 || m > 9) {
            cout << "Invalid row or column. Please enter values between 1 and 9." << endl;
            continue;
        }

        cout << "Enter number (1-9): ";
        cin >> number;

        if (number < 1 || number > 9) {
            cout << "Invalid number. Please enter a value between 1 and 9." << endl;
            continue;
        }

        if (!checkValid(board, n - 1, m - 1, number)) {
            cout << "Invalid move. Number already present in row, column, or subgrid." << endl;
            continue;
        }

        board[n - 1][m - 1] = number;
        print();
    }
}

bool Sudoku::checkValid(const vector<vector<int>>& board, int row, int column, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (board[i][column] == num) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = column - column % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::solver(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (checkValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solver(board)) {
                            return true;
                        } else {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Sudoku::implementation() {
    int choice;
    do {
        cout << "Sudoku Main Menu:" << endl;
        cout << "1. Input numbers" << endl;
        cout << "2. Solve Sudoku" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputNumbers();
                break;
            case 2:
                if (solver(board)) {
                    cout << "Here is the solved Sudoku:" << endl;
                    print();
                } else {
                    cout << "No solution exists for the given Sudoku." << endl;
                }
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                break;
        }
    } while (choice != 3);
}
