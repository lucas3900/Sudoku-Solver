/* ##########################################################################
# #
# sudokuboard.cc #
# Lucas Barusek #
# 3/5/19 #
# #
Creates a sudoku board using dynamically created array of arrays. Each
array in the big array will have a character in it, either a number
or an underscore(representing unassigned). The sudoku board will be
able to place characters at each location, get the character at a location,
remove a character at a location, check if a character can be placed at
a location, print the board, and check if the sudoku board is solved.
# #
########################################################################## */

#include <iostream>
#include "sudokuboard.h"

sudoku_board::sudoku_board(){
  /* constructor for sudoku board */

  // sets board equal to nine arrays, and places nine arrays in each of
  // the nine arrays
  board = new char*[9];
  for (size_t i = 0; i < 9; i++)
    board[i] = new char[9];
}

void sudoku_board::place(size_t r, size_t c, char n){
  /* places a num at a given row and col location on the board */
  board[r][c] = n;
}

void sudoku_board::print(){
  /* prints the board */

  //prints the board in 9 rows of charaters, emulating a sudoku board
  for (size_t row = 0; row < 9; row++){
    for (size_t col = 0; col < 9; col++)
      std::cout << board[row][col];
    std::cout << std::endl;
  }
}

char sudoku_board::get(size_t r, size_t c){
  /* returns the character at a given row and col location */
  return board[r][c];
}

void sudoku_board::remove(size_t r, size_t c){
  /* removes a num at a given row and col location by setting it equal
  to a an underscore */
  board[r][c] = '_';
}


bool sudoku_board::can_place(size_t r, size_t c, size_t n){
  /* returns true if the passed num (n) can be placed at a given
  row and col in accordance with the rules of sudoku */

  // converts the size_t num to it's character equivalent
  char num = n + '0';

  // returns false if a number is already placed at the location
  if (board[r][c] != '_')
    return false;

  //returns false if the num has already been used in the row and column
  // the number is trying to be placed in
  for (size_t row_or_col = 0; row_or_col < 9; row_or_col++)
    if (board[r][row_or_col] == num or board[row_or_col][c] == num)
      return false;

  // determines the starting row and column of the 3 X 3 square the number
  // is trying to be placed in
  r = r / 3 * 3;
  c = c / 3 * 3;

  // iterates through the 3 X 3 square the num is trying to placed in
  // and returns false if the num has already been used in it
  for (size_t row = 0; row < 3; row++)
    for (size_t col = 0; col < 3; col++){
      if (board[r + row][c + col] == num)
        return false;
      }

  // returns true if the num abides by all the rules of sudoku and
  // can be placed
  return true;
}

bool sudoku_board::solved(){
  /* returns true if the board has been solved */

  // iterates through the board and returns false if an underscore is
  // found anywhere, indicating the board has not been solved
  for(size_t row = 0; row < 9; row++)
    for (size_t col = 0; col < 9; col++){
      if (board[row][col] == '_')
        return false;
    }
    return true;
}
