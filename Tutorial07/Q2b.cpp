#include <iostream>
#include <iomanip>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void swap( DataType&, DataType& );
void displayArray( const DataType[], int );
void bubbleSort( DataType[], int );
void displayArray( const DataType[], int );

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };

   cout << "Initial array : ";
   displayArray( a, N_ITEMS );
   cout << endl;

   bubbleSort( a, N_ITEMS );

   cout << "Sorted array : ";
   displayArray( a, N_ITEMS );
   cout << endl;

   return 0;
}

void swap(DataType& x, DataType& y){
   DataType temp = x;
   x = y;
   y = temp;
   cout << "Swapped " << setw(2) << x << " with " << setw(2) << y << " --->";
}

void displayArray( const DataType theArray[], int size ){
   for ( int i = 0; i < size; ++i )
      cout << setw(2) << theArray[ i ] << " ";
}

void bubbleSort(DataType theArray[], int n){
   bool sorted;  // false if swaps occur

   for (int pass = 1; (pass < n) && !sorted; ++pass){
      sorted = true;  // assume sorted
      for (int index = 0; index < n-pass; ++index){
         if (theArray[index] > theArray[index+1])
         {
            swap(theArray[index], theArray[index+1]);
            sorted = false;  // signal exchange
            displayArray( theArray, n );
            cout << endl;
         }
      }
   }
}
