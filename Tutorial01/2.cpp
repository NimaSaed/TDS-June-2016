/*******************************************************************************

	Your Task:
		This program accepts a name from the user
		and display the text as shown in the sample run.
		However, there are syntax as well as logical errors
		in the program.

		Correct the errors such that given the sample input below,
		the output will be correct as indicated.

	Sample run 1:
   		Enter a name -> william
   		Output : william illiam lliam liam iam am m

 	Sample run 2:
   		Enter a name -> cyberjaya
   		Output : cyberjaya yberjaya berjaya erjaya rjaya jaya aya ya a

*******************************************************************************/

#include <iostream>
// #include <cstdlib>
using namespace std;

int main()
{
   char name[20];
   char *ptr1,*ptr2;

   cout << "Enter a name -> ";
   cin >> name;
   cout << "Output : ";

   for (ptr1 = name; *ptr1 != '\0'; ptr1++)
   {
      for (ptr2 = ptr1; *ptr2 != '\0'; ptr2++)
      {
         cout << *ptr2;
      }
      cout << ' ';
   }

   //system("pause");
   return 0;
}

   /*
   Name == 0x1000             ptr1 == 0x1005            prt2  == 0x1005
   Address    Data
   0x1000     'A'
   0x1001     'p'
   0x1002     'p'
   0x1003     'l'
   0x1004     'e'
   0x1005     '\0'

   */
