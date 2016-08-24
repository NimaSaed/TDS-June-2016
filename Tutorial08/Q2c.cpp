#include <iostream>
#include <sstream> //stringstream
using namespace std;

typedef int DataType;
const int N_ITEMS = 10;
const int length = 2;

void radixSort(string[], int, int );
void displayArray( const DataType[], int, int );

int main(){
   DataType a[ N_ITEMS ] = { 10, 5, 21, 5, 99, 8, 16, 4, 72, 25 };
   string s[ N_ITEMS ];

   cout << "Initial array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   // Convert each element to string
   for ( int i = 0; i < N_ITEMS; i++ ){
      stringstream ss;
      ss << a[i];
      s[i] = ss.str();
      for(int j=s[i].length(); j<length; j++)
        s[i]= "0" + s[i];
   }

   radixSort( s, N_ITEMS, length );

   // Convert each element to integer
   for ( int i = 0; i < N_ITEMS; i++ ){
      stringstream ss;
      ss << s[i];
      ss >> a[i];
   }

   cout << "Sorted array : ";
   displayArray( a, 0, N_ITEMS - 1 );
   cout << endl;

   return 0;
}

void displayArray( const DataType theArray[], int first, int last ){
   for ( int i = first; i <= last; ++i )
      cout << theArray[ i ] << " ";
}

void radixSort(string theArray[], int size, int length){
   //10 groups, 0-9, with each having a max of N_ITEMS
   string tempArray[ 10 ][ size ];
   //number of items in each groups
   int endPoint[ 10 ];
   //grouping from lowest power to highest
   for ( int j = length - 1; j >= 0; j-- ){

      // Initialize tempArray to empty
      for( int i = 0; i < 10; i++ )
	     for( int k = 0; k < size; k++ )
            tempArray[ i ][ k ] = "";

      // Initialize all end points to 0
      for( int i = 0; i < 10; i++ )
         endPoint[ i ] = 0;

      //grouping
      for ( int index = 0; index < size; index++ ){
         // k = j-th digit of theArray[ index ]
         // get group number, k for theArray[index]
         int k =  theArray[ index ][ j ] - '0';

         // Place theArray[ index ] at the end of group k
         tempArray[ k ][ endPoint[ k ] ] = theArray[ index ];

         // Increment the end point (number of items) of group k by 1
         endPoint[ k ]++;
      }

      // Replace the items in theArray with all the items
      // in group 0, followed by all the items in group 1,
      // and so on
      cout << "Grouped by digit " << j + 1 << "-th : ";

      int index = 0;

      for( int i = 0; i < 10; i++ ){ //iterate groups
         cout << "[";
         for( int k = 0; k < endPoint[ i ]; k++ ){ //while group has items
            theArray[ index ] = tempArray[ i ][ k ];
            cout << theArray[ index ] << " ";
            index = index + 1;
         }
         cout << "]";
      }
      cout << endl;
   }

}






