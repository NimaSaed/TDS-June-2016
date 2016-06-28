#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
   double *d;            // d is a variable whose purpose
                         // is to contain the address of a
                         // zone where a double is located.
                         // It is a pointer of type double.


   d = new double;       // new allocates a zone of memory
                         // large enough to contain a double
                         // and returns its address.
                         // That address is stored in d.

   *d = 45.3;           // The number 45.3 is stored
                         // inside the memory zone
                         // whose address is given by d.

   cout << "Type a number: ";
   cin >> *d;

   *d = *d + 5;

   cout << "Result: " << *d << endl;

    cout << "Address of d: " << &d << endl;
    cout << "Value of d : " << *d << endl;
    cout << "Value that d is pointing to : " << d << endl;


   delete d;             // delete deallocates the
                         // zone of memory whose address
                         // is given by pointer d.
                         // Now we can no more use that zone.


   d = new double[15];   // allocates a zone for an array
                         // of 15 doubles. Note each 15
                         // double will be constructed.
                         // This is pointless here but it
                         // is vital when using a data type
                         // that needs its constructor be
                         // used for each instance.

   d[0] = 4456;
   d[1] = d[0] + 567;

   cout << "Content of d[1]: " << d[1] << endl;

   delete [] d;          // delete [] will deallocate the
                         // memory zone. Note each 15
                         // double will be destructed.
                         // This is pointless here but it
                         // is vital when using a data type
                         // that needs its destructor be
                         // used for each instance (the ~
                         // method). Using delete without
                         // the [] would deallocate the
                         // memory zone without destructing
                         // each of the 15 instances. That
                         // would cause memory leakage.

   int n = 30;

   d = new double[n];    // new can be used to allocate an
                         // array of random size.
   for (int i = 0; i < n; i++)
   {
      d[i] = i;
      // cout << d[i] << endl;
   }
   delete [] d;

   char *s;
   s = new char[100];
   strcpy (s, "Hello!");
   cout << s << endl;
   delete [] s;

   //system( "PAUSE" );
   return 0;
}
