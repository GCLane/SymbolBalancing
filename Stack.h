/* 8/31/98 Mary Elaine Califf
 * a C++ array implementation of stacks
 *
 * Revised 12/25/2020
 */
 // Grant Lane and Mary Elaine Califf
 //Header file for a stack of integers

#ifndef STACK_H
#define STACK_H

class Stack
{

public:

  Stack(); // constructor

  Stack(const Stack& copyStack); //copy constructer

  ~Stack(); //destructor

  Stack operator=(const Stack& theStack); //overide the assignment operation

  // add a new value to the stack
  void push(char newValue);

  // pops top item off of the stack
  // Precondition: stack must not be empty
  char pop();

  // return item at the top of the stack without removing it
  // Precondition: stack must not be empty
  char top() { return head->data; }

  bool isEmpty() { return (head == nullptr);} 

private:

  struct Node
  {
    char data;
    Node* next;

    Node(char dataVal, Node* nextPtr = nullptr) : data(dataVal), next(nextPtr){}
  };
  Node* head;

  void clear();
  void copy(const Stack& copyStack);

};
#endif
