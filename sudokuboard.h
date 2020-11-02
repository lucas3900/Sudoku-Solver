/* ##########################################################################
# #
# sudokuboard.h #
# Lucas Barusek #
# Project 3: Sudoku #
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

class sudoku_board{
public:
  sudoku_board(); // constructor for sudoku board

  // places a num at a location on the board
  void place(size_t r, size_t c, char n);
  void print(); //prints the sudoku board
  char get(size_t r, size_t c); // returns the num placed at a location

  // removes the num at a location on the board and sets it to an underscore
  void remove(size_t r, size_t c);

  //checks if a num can be placed at a location in accordance with the
  // rules of sudoku
  bool can_place(size_t r, size_t c, size_t n);
  bool solved(); // returns true if the sudoku puzzle is solved
private:
  char **board; //dynamically created array of arrays to create board
};
