/* ##########################################################################
# #
# stack.h #
# Lucas Barusek #
# Project 3: Sudoku #
# 3/5/19 #
# #
A Linked list based stack which stores data in a linked list of nodes.
This stack supports push, pop, top and empty.
# #
########################################################################## */

#include <cstdlib>

//redefines size_t as stack_element for readability
typedef size_t stack_element;


class node{
  /* node class; the node will have a data field to store information
  and a next field to point at the next node to create a linked list */
public:
  stack_element data; // data field
  node*next;          // next field pointer
  node(const stack_element & d, node * n); // node constuctor
};

class stack{
  /* stack class; the stack will be comprised of a linked list of nodes,
  which will be used to store the row, col, and num data for sudoku */
private:
  node *_top = NULL; //node pointer to point at node on top of the stack
public:
  void _init(); // stack constructor
  void push(const stack_element & item); // pushes item on stack (adds)
  void pop(); // pops items off of stack (removes)
  int top() const; // returns what's on top of the stack
  bool empty() const; // returns true if stack is empty
};
