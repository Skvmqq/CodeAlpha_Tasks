//
// Created by shiva on 29-05-2024.
//

#ifndef SUDUKUSOLVER_SUDOKU_H
#define SUDUKUSOLVER_SUDOKU_H
#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>

class Sudoku {
public:
    Sudoku();
    void print();
    void inputNumbers();
    bool solver(std::vector<std::vector<int>>& board);
    bool checkValid(const std::vector<std::vector<int>>& board, int row, int column, int num);
    void implementation();

private:
    std::vector<std::vector<int>> board;
    bool choice;
};

#endif // SUDOKU_H





#endif //SUDUKUSOLVER_SUDOKU_H
