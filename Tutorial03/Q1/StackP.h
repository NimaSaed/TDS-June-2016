#ifndef STACKP
#define STACKP

/** @file StackP.h */

#include "StackException.h"
typedef char StackItemType;

/** ADT stack - Pointer-based implementation. */
class Stack
{
   public:
   // Constructors and destructor:

   /** Default constructor. */
   Stack();

   /** Copy constructor.
    * @param aStack The stack to copy. */
   Stack(const Stack& aStack);

   /** Destructor. */
   ~Stack();

   // Stack operations:
   bool isEmpty() const;
   void push(const StackItemType& newItem) throw(StackException);
   void pop() throw(StackException);
   void pop(StackItemType& stackTop) throw(StackException);
   void getTop(StackItemType& stackTop) const
      throw(StackException);

   private:
   /** A node on the stack. */
   struct StackNode
   {
      /** A data item on the stack. */
      StackItemType item;
      /** Pointer to next node.     */
      StackNode    *next;
   }; // end StackNode

   /** Pointer to first node in the stack. */
   StackNode *topPtr;
}; // end Stack
// End of header file.

#endif
