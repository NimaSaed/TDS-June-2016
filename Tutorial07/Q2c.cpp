#include <iostream>
#include <iomanip>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void insertionSort( DataType theArray[], int n );
void displayArray( const DataType theArray[], int first, int last );

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };

   cout << "Initial array : ";
   displayArray( a, 0, N_ITEMS-1 );
   cout << endl;

   insertionSort( a, N_ITEMS );

   cout << "Sorted array : ";
   displayArray( a, 0, N_ITEMS-1 );
   cout << endl;

   return 0;
}

void displayArray( const DataType theArray[], int first, int last ){
   for ( int i = first; i <= last; ++i )
      cout << setw(2) << theArray[ i ] << " ";
}

void insertionSort(DataType theArray[], int n){
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region
   for ( int unsorted = 1; unsorted < n; ++unsorted ){
      DataType nextItem = theArray[ unsorted ]; //COPY
      int loc = unsorted;
      //find where to place nextItem in sorted list
      while ( ( loc > 0 ) && ( theArray[ loc - 1 ] > nextItem) ){
         //if prev > nextItem, shift right
         theArray[ loc ] = theArray[ loc - 1 ];//SHIFT
         loc = loc - 1;
      }
      // insert nextItem into Sorted region
      theArray[loc] = nextItem;//INSERT

      cout << "Insert " << setw(2) << nextItem << " into location " << setw(2) << loc << " ---> ";

      //displayArray( theArray, n );
      displayArray(theArray, 0, unsorted); cout << " | ";
      displayArray(theArray, unsorted+1, n-1);
      cout << endl;
   }
}
