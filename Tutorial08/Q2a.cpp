#include <iostream>
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;

void displayArray( const DataType theArray[], int first, int last );
void merge( DataType theArray[], int first, int mid, int last );
void mergeSort( DataType theArray[], int first, int last );

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };

   cout << "Initial array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   mergeSort( a, 0, N_ITEMS - 1 );

   cout << "Sorted array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   return 0;
}

void displayArray( const DataType theArray[], int first, int last ){
   for ( int i = first; i <= last; ++i )
      cout << theArray[ i ] << " ";
}

void merge(DataType theArray[], int first, int mid, int last ){
   DataType tempArray[N_ITEMS];    // temporary array

   // initialize the local indexes to indicate the subarrays
   int first1 = first; 3       // beginning of first subarray
   int last1  = mid;   2      // end of first subarray
   int first2 = mid + 1; 4     // beginning of second subarray
   int last2  = last;    4    // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index; //index of tmp array
   for (index=first; (first1 <= last1) && (first2 <= last2); ++index){
      if (theArray[first1] < theArray[first2]){
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else{
         tempArray[index] = theArray[first2];
         ++first2;
      }
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      tempArray[index] = theArray[first1];

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      tempArray[index] = theArray[first2];

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
}

void mergeSort(DataType theArray[], int first, int last){
   if (first < last){ // more than 1 element in list
      int mid = (first + last)/2;    // index of midpoint

      cout << "Sorting left half  ---> ";
      displayArray( theArray, first, mid );
      cout << endl;
      mergeSort( theArray, first, mid );

      cout << "Sorting right half ---> ";
      displayArray( theArray, mid + 1, last );
      cout << endl;
      mergeSort( theArray, mid + 1, last );

      merge( theArray, first, mid, last );
      cout << "Merged two halves  ---> ";
      displayArray( theArray, first, last );
      cout << endl;
   }
}
