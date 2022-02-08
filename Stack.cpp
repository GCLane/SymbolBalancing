/* 8/31/98 Mary Elaine Califf
 * a C++ linked list implementation of stacks
 */

// Modified:
//   8/20/2003 by Mary Elaine Califf
//      Changed to ANSI C++
// revised 12/25/20
//Grant Lane and Mary Elaine Califf
//Implementation of a stack of integers

#include <iostream>
#include "Stack.h"
using namespace std;



Stack::Stack()
{
  head = nullptr;
}

Stack::Stack(const Stack& copyStack)
{
  copy(copyStack);
}
//Private copy method that does a deep copy of the Stack
void Stack::copy(const Stack& copyStack)
{
  if(copyStack.head == nullptr)
    head = nullptr;
  else 
  {
    head = new Node(copyStack.head->data);
    Node* ptr1 = copyStack.head->next;
    Node* ptr2 = head;

    while(ptr1)
    {
      Node* temp = new Node(ptr1->data);

      ptr2->next = temp;
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }
}

//

Stack::~Stack()
{
  //insert into a clear method
  clear();
}
//Private clear method to be used in the deconstructor and assignment methods
void Stack::clear()
{
  Node* curPtr = head;
  while(curPtr)
  {
    Node* deleteNode = curPtr;
    curPtr = curPtr->next;
    delete deleteNode;
  }
}

Stack Stack::operator=(const Stack& theStack)
{
  if(this != &theStack)
  {
    clear();
    copy(theStack);
  }

  return *this;
}

void Stack::push(char newValue)
{
  Node* temp = new Node(newValue);

  if(isEmpty())
    head = temp;
  else
  {
    temp->next = head;
    head = temp;
  }

}

char Stack::pop()
{
  // taking advantage of pre-increment so we don't have to save the value off to return it
  Node* temp = head;
  char sym = temp->data;
  head = head->next;
  delete temp;
  return sym;
}
