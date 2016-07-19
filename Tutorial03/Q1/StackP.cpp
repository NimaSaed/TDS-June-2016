/** @file StackP.cpp */

#include <cstddef>   // for NULL
#include <new>       // for bad_alloc
#include "StackP.h"  // header file

using namespace std;

Stack::Stack() : topPtr(NULL)
{
}  // end default constructor

Stack::Stack(const Stack& aStack)
{
   if (aStack.topPtr == NULL)
      topPtr = NULL;  // original list is empty

   else
   {  // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of list
      StackNode *newPtr = topPtr;    // new list pointer
      for (StackNode *origPtr = aStack.topPtr->next;
	   origPtr != NULL;
	   origPtr = origPtr->next)
      {  
         newPtr->next = new StackNode;
         newPtr = newPtr->next;
	 newPtr->item = origPtr->item;
      }  // end for

      newPtr->next = NULL;
   }  // end if
}  // end copy constructor

Stack::~Stack()
{
   // pop until stack is empty
   while (!isEmpty())
      pop();
   // Assertion: topPtr == NULL
}  // end destructor

bool Stack::isEmpty() const
{
   return topPtr == NULL;
}  // end isEmpty

void Stack::push(const StackItemType& newItem)
            throw(StackException)
{
   // create a new node
   try
   {
      StackNode *newPtr = new StackNode;

      // set data portion  of new node
      newPtr->item = newItem;

      // insert the new node
      newPtr->next = topPtr;
      topPtr = newPtr;
   }
   catch (bad_alloc e)
   {
      throw StackException(
	 "StackException: push cannot allocate memory.");
   }  // try
}  // end push

void Stack::pop() throw(StackException)
{
   if (isEmpty())
      throw StackException("StackException: stack empty on pop");
   else
   {  // stack is not empty; delete top
      StackNode *temp = topPtr;
      topPtr = topPtr->next;
      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
   }  // end if
}  // end pop

void Stack::pop(StackItemType& stackTop) throw(StackException)
{
   if (isEmpty())
      throw StackException("StackException: stack empty on pop");
   else
   {  // stack is not empty; retrieve and delete top
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
   }  // end if
}  // end pop

void Stack::getTop(StackItemType& stackTop) const throw(StackException)
{
   if (isEmpty())
      throw StackException("StackException: stack empty on getTop");
   else
      // stack is not empty; retrieve top
      stackTop = topPtr->item;
}  // end getTop
// End of implementation file.
