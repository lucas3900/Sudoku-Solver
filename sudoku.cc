/* ##########################################################################
# #
# Sudoku.cc #
# Lucas Barusek #
# Project 3: Sudoku #
# 3/5/19 #
# #
This code takes input of a partially filled sudoku board which has a unique
solution, and fills in all the missing numbers until the board is solved
following the standard rules of sudoku. This code utilizes a linked list stack
to keep track of sudoku board information, and this code utilizes back-
tracking to solve the board.
# #
########################################################################## */

#include <iostream>
#include "sudokuboard.h"
#include "stack.h"

void determine_constrained(sudoku_board _board, size_t & row, size_t & col){
  /* determines the location on the sudoku board that can take the fewest
   amount of numbers, and assigns the coordinates of that location to
   the reference varibles row and col  */

  // count will keep track of how many numbers each location can take
  // check will be the bar for which we compare if a location takes fewer
  // numbers than any other location
  size_t count = 0;
  size_t check = 10;

  // iterates through each location of the sudoku board, and sets the
  // count for each location equal to zero
  for (size_t r = 0; r < 9; r++){
    for (size_t c = 0; c < 9; c++){
      count = 0;

      // iterates through the nine possible sudoku numbers, and checks
      // if that number can be placed at the location; adds one to count
      // for each number that can be placed
      for (size_t num = 1; num < 10; num++){
        if (_board.can_place(r, c, num)){
          count++;
          }
        }


      // checks if the location takes fewer numbers than the location
      // that previouly took the fewest numbers. If so, sets the row
      // and column equal to that location, and sets the check equal to
      // the new lowest amount of numbers accepted
      if ((count < check) and (count > 0)){
        row = r;
        col = c;
        check = count;
      }
    }
  }
}

bool solve_sudoku(sudoku_board & _board){
  /* Solves the sudoku board by placing the smallest possible number
  at the most constrained location, and if no number can be placed,
  backtracks through the previous locations and tries different
  numbers until the board can be solved  */

  // creates a stack, varaibles to store the row and column locations,
  // and created a varaible to keep track of what number is placed
  // at each location
  stack stackie;
  size_t row = 0, col = 0, num = 0;

  // array to convert size_t numbers to character numbers
  const char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  // determines the most constrained spot on the sudoku board
  determine_constrained(_board, row, col);

  // code iterates for as long as the board is not solved
  while(!_board.solved()){

    // checks if no number can be places at a location; if so backtracks
    if(num > 8){

      // gets the number at the previous location and increments it by one
      num = 1 + stackie.top();

      // gets the row and column data of the previouly placed number from
      //the stack, and removes the number since it triggered a dead end
      stackie.pop();
      row = stackie.top();
      stackie.pop();
      col = stackie.top();
      stackie.pop();
      _board.remove(row, col);
    }

    // checks if the current num can be placed at the current location
    else if(_board.can_place(row, col, num + 1)){

      // places the num on the board, and stores the row, col, and num
      // data of the location
      _board.place(row, col, numbers[num]);
      stackie.push(col);
      stackie.push(row);
      stackie.push(num);

      // determines the next most constrained spot on the board, and sets
      // num equal to zero in order to try and place the lowest number
      // at the location
      determine_constrained(_board, row, col);
      num = 0;
    }

    //checks if the current num can't be placed
    else{
      // increments num by one in order to try and place the next
      // smallest number at the location
      num++;
    }
  }

  // returns true when the board is solved
  return true;
}


int main(){
  /* The main function which creates the sudoku board */

  sudoku_board _board;   // creates a sudoku board
  //reads the user inputted sudoku board and sets the inputted data
  //in the board
  std::string one;
  for(size_t row = 0; row < 9; row++){
    std::cin >> one;
    for(size_t col = 0; col < 9; col++)
      _board.place(row, col, one[col]);
    }

    // prints the sudoku board when it is solved
  if (solve_sudoku(_board))
    _board.print();
}
