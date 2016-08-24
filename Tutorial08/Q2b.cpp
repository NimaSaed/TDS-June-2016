#include <iostream>
#include <iomanip>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void swap( DataType&, DataType& );
void displayArray( const DataType[], int, int );
void quickSort(DataType[], int, int);
void partition(DataType[], int, int, int&);

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };

   cout << "Initial array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   quickSort( a, 0, N_ITEMS - 1 );

   cout << "Sorted array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   return 0;
}

void swap(DataType& x, DataType& y){
   DataType temp = x;
   x = y;
   y = temp;
   cout << "Swapped " << setw(2) << x << " with " << setw(2) << y << " --->";
}

void displayArray( const DataType theArray[], int first, int last ){
   for ( int i = first; i <= last; ++i )
      cout << setw(2) << theArray[ i ] << " ";
}

void partition(DataType theArray[], int first, int last, int& pivotIndex){
   DataType pivot = theArray[first];     // Use the first element
   cout << "Pivot = " << pivot << endl;
   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown
   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; firstUnknown++){
      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot){
         // item from unknown belongs in S1
         swap(theArray[firstUnknown], theArray[lastS1+1]);
         lastS1++;
         displayArray( theArray, first, last ); cout << endl;
      }
      // else item from unknown belongs in S2: firstUnknown++
   }
   // place pivot in proper position and mark its location
   cout << "Pivot "; swap(theArray[first], theArray[lastS1]);
   displayArray( theArray, first, last ); cout << endl;

   cout << "After partitioning : ";
   displayArray( theArray, first, last ); cout << endl << endl;

   pivotIndex = lastS1;
}

void quickSort(DataType theArray[], int first, int last){
   //locate pivotIndex with partition, then sort S1 and S2
   int pivotIndex;
   if (first < last)
   {
      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      cout << "Quick sort S1 region : ";
      displayArray( theArray, first, pivotIndex-1 );
      cout << endl;
      quickSort(theArray, first, pivotIndex-1);

      cout << "Quick sort S2 region : ";
      displayArray( theArray, pivotIndex+1, last );
      cout << endl;
      quickSort(theArray, pivotIndex+1, last);
   }
}






