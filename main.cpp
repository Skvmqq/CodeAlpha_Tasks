#include <iostream>
#include "Sudoku.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Sudoku suduku;
    std::cout<<"Printing empty suduku board"<<std::endl;
    suduku.print();
    suduku.inputNumbers();
    suduku.implementation();
    return 0;
}
