
#include <iostream>    // Only for displaying copy constructor
#include <fstream>     // for file I/O
#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "ListException.h"
#include "ListIndexOutOfRangeException.h"
typedef string ListItemType;
//#include "ListP.h"     // header file

using namespace std;

class List
{
   public:
   // Constructors and destructor:

      /** Default constructor. */
      List();

      /** Copy constructor.
       * @param aList The list to copy. */
      List(const List& aList);

      /** Destructor. */
      ~List();


   // List operations:
      bool isEmpty() const;
      int getLength() const;
      void insert(int index, const ListItemType& newItem)
	    throw(ListIndexOutOfRangeException, ListException);
      void remove(int index)
	    throw(ListIndexOutOfRangeException);
      void retrieve(int index, ListItemType& dataItem) const
	    throw(ListIndexOutOfRangeException);
      void save( string fileName );
      void load( string fileName )
        throw( ListException );

   private:
      /** A node on the list. */
      struct ListNode
      {
         /** A data item on the list. */
         ListItemType item;
         /** Pointer to next node. */
         ListNode    *next;
      }; // end ListNode

      /** Number of items in list. */
      int       size;
      /** Pointer to linked list of items. */
      ListNode *head;

      /** Locates a specified node in a linked list.
       * @pre index is the number of the desired node.
       * @post None.
       * @param index The index of the node to locate.
       * @return A pointer to the index-th node. If index < 1
       *         or index > the number of nodes in the list,
       *         returns NULL. */
      ListNode *find(int index) const;
};

List::List() : size( 0 ), head( NULL )
{
}//end default constructor

List::~List()
{
   while (!isEmpty())
      remove(1);
}  // end destructor


List::List(const List& aList)
   : size(aList.size)
{
   cout << "Copy Constructor" << endl;
   if ( aList.head == NULL )
   {
      head = NULL;  // original list is empty
   }
   else
   {
      // copy first node
      head = new ListNode;
      head->item = aList.head->item;

      // copy rest of list
      ListNode *newPtr = head;  // new list pointer
      // newPtr points to last node in new list
      // origPtr points to nodes in original list
      for (ListNode *origPtr = aList.head->next;
	       origPtr != NULL;
           origPtr = origPtr->next)
      {
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
	     newPtr->item = origPtr->item;
      }  // end for

      newPtr->next = NULL;
   }  // end if
}  // end copy constructor


bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength

//input index, return node
//helper function
List::ListNode *List::find(int index) const
{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }  // end if
}  // end find

void List::retrieve(int index,
                    ListItemType& dataItem) const
   throw(ListIndexOutOfRangeException)
{
   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	    "ListIndexOutOfRangeException: retrieve index out of range");
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item;
   }  // end if
}  // end retrieve

void List::insert(int index, const ListItemType& newItem)
   throw(ListIndexOutOfRangeException, ListException)
{
   int newLength = getLength() + 1;

   if ( (index < 1) || (index > newLength) )
      throw ListIndexOutOfRangeException(
	    "ListIndexOutOfRangeException: insert index out of range");
   else
   {
      // try to create new node and place newItem in it
      try
      {
         ListNode *newPtr = new ListNode;
         newPtr->item = newItem;
         size = newLength;

         // attach new node to list
         if (index == 1)
         {  // insert new node at beginning of list
            newPtr->next = head;
            head = newPtr;
         }
         else
         {  ListNode *prev = find(index-1);
            // insert new node after node
            // to which prev points
            newPtr->next = prev->next;
            prev->next = newPtr;
         }  // end if
      }  // end try
      catch (bad_alloc e)
      {
	    throw ListException(
	      "ListException: memory allocation failed on insert");
      }  // end catch
   }  // end if
}  // end insert

void List::remove(int index) throw(ListIndexOutOfRangeException)
{
   ListNode *cur;

   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	   "ListIndexOutOfRangeException: remove index out of range");
   else
   {
      --size;
      if (index == 1)
      {  // delete the first node from the list
         cur = head;  // save pointer to node
         head = head->next;
      }

      else
      {  ListNode *prev = find(index - 1);
         // delete the node after the node to which prev points
         cur = prev->next;  // save pointer to node
	     prev->next = cur->next;
      }  // end if

      // return node to system
      cur->next = NULL;
      delete cur;
      cur = NULL;
   }  // end if
}  // end remove


void List::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item << endl;
   }
   outFile.close();
}

void List::load( string fileName ) throw( ListException )
{
   ifstream inFile( fileName.c_str() );
   ListItemType nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove( 1 );
   }
   size = 0;

   if ( inFile >> nextItem ) // Is file empty?
   {  // File not empty:
      try
      {
         head = new ListNode;
         // Add the first integer to the list.
         head->item = nextItem;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( inFile >> nextItem )
         {
            tail->next = new ListNode;
            tail = tail->next;
            tail->item = nextItem;
            tail->next = NULL;
            size = size + 1;
         }  // end while
      }  // end try
      catch (bad_alloc e)
      {
          throw ListException(
         "ListException: restore cannot allocate memory.");
      }  // end catch
   }  // end if

   inFile.close();
}

