/* ##########################################################################
# #
# stack.cc #
# Lucas Barusek #
# Project 3: Sudoku #
# 3/5/19 #
# #
A Linked list based stack which stores data in nodes. This stack supports
push, pop, top and empty.
# #
########################################################################## */

#include "stack.h"
#include <cassert>
#include <iostream>


node::node(const stack_element & d, node * n){
  /* node constuctor that creates a node with a data field that will
   contain characters, and a node pointer that will point at the next node*/

  data = d;
  next = n;
}

void stack::_init(){
  /* constructor for stack */
  _top = NULL;
}

void stack::push(const stack_element & item){
  /* pushes an item (adds and item) onto a stack by creating a new node
  with the passed stack_element in the data field, what top was previously
  pointing to in the next field, and then has top point to the new node */
   _top = new node(item, _top);
}

void stack::pop() {
  /* Pops the last thing pushed onto the stack (deletes the item). There
  must be an item in the stack if this method is called */
  assert(!empty());

  // creates a new node which points at what _top is pointing at.
  node * condemned = _top;

  // top is now pointing at the next node in the stack
  _top = _top->next;

  // delets the first node in the list
  delete condemned;
}

int stack::top() const{
  /* returns the last item that was pushed on the stack. There must
  be something on the stack for this code to run */
  assert(!empty());
  return (_top->data);
}

bool stack::empty() const{
  /* returns true if the stack is empty, by checking the _top pointer
  is not pointing at anything, indicating there is nothing in the stack */
  return _top == NULL;
}
