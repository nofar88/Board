#include <iostream>
#include <string>
#include "Board.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;



void Board::post(unsigned int row, unsigned int column, Direction way, string s) {

    unsigned int lens = s.length();
    for (unsigned int  i = 0; i < lens; ++i) {
        matrix[row + (way == Direction::Vertical ? i : 0)][column + (way == Direction::Horizontal ? i : 0)] = s[i];// Insert the word in the appropriate row and column
    }

    if (way == Direction::Vertical) {
        row += lens;
    } else {
        column += lens;
    }

    if (lenr < row) {
        lenr = row - 1;
    }
    if (lenc < column) {
        lenc = column - 1;
    }
}

string Board::read(unsigned int row, unsigned int column, Direction way, unsigned int len) {
    string ad;
    for (unsigned int i = 0; i < len; ++i) {
        unsigned int newRow = row + (way == Direction::Vertical ? i : 0);
        unsigned int newCol = column + (way == Direction::Horizontal ? i : 0);
        if (matrix.count(newRow) != 0 && matrix[newRow].count(newCol) != 0) {//Checks that the row also exists and checks that both the row and the column exist
            ad += matrix[newRow][newCol];
        } else {
            ad += "_";
        }
    }
    return ad;
}


void Board::show() {
    for (unsigned int i = 0; i <= lenr; ++i) {
        for (unsigned int j = 0; j <= lenc; ++j) {
            if (matrix.count(i) != 0 && matrix[i].count(j) != 0) {
                cout << matrix[i][j];
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
}
