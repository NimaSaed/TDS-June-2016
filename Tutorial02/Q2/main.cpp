
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ListP.cpp"

using namespace std;

int main()
{
  char choice;
  bool done = false;
  List alist;
  do
  {

    cout << endl << endl << endl;
    cout << "          1. Add Record To Back" << endl;
    cout << "          2. Insert a Record" << endl;
    cout << "          3. Erase a Record by Record Number" << endl;
    cout << "          4. Remove A Record by Content" << endl;
    cout << "          5. Clear ALL Records" << endl;
    cout << "          6. Display A Record" << endl;
    cout << "          7. Display ALL Records" << endl;
    cout << "          8. Save Records to File" << endl;
    cout << "          9. Load Records from File" << endl;
    cout << "          Q. Quit" << endl;
    cout << endl;
    cout << "        => ";
    cin >> choice;
    choice = toupper(choice);

    ListItemType ch, content;
    char yesorno;
    string filename;
    int recno;

    switch( choice )
    {
      case '1' :
         cout << "Character to add to back => ";
         cin >> ch;
         alist.insert( alist.getLength() + 1, ch );
         break;

      case '2' :
         cout << "Record number to insert => ";
         cin >> recno;
         cout << "Character to insert => ";
         cin >> ch;
         alist.insert( recno, ch );
         break;

      case '3' :
         cout << "Record number to erase => ";
         cin >> recno;
         alist.remove( recno );
         break;

      case '4' :
         cout << "Character to remove => ";
         cin >> ch;
         for( int i = 1; i <= alist.getLength(); ++i )
         {
             alist.retrieve( i, content );
             if ( content == ch )
             {
                alist.remove( i );
                break;
             }
         }
         break;

      case '5' :
         cout << "Clear ALL records ? (Y/N) => ";
         cin >> yesorno;
         yesorno = toupper(yesorno);
         if ( yesorno == 'Y' )
	 {
            while( !alist.isEmpty() )
            {
               alist.remove( 1 );
            }
         }
         break;

      case '6' :
         cout << "Record number to display => ";
         cin >> recno;
         alist.retrieve( recno, content );
         cout << "Data for Record Number " << recno << endl;
         cout << "----------------------------" << endl;
         cout << "[";
         cout << content;
         cout << "]" << endl;;
         cout << "----------------------------" << endl;
         break;

      case '7' :
         cout << "Data for ALL Records" << endl;
         cout << "----------------------------" << endl;
         for( int i = 1; i <= alist.getLength(); ++i )
         {
            alist.retrieve( i, content );
            cout << content;
         }
         cout << endl;
         cout << "----------------------------" << endl;
         break;

      case '8' :
         cout << "Save records to? File name = ";
         cin >> filename;
         alist.save( filename );
         break;

      case '9' :
         cout << "Load records from? File name = ";
         cin >> filename;
         alist.load(filename);
         break;

      case 'Q' :
         done = true;
         break;

      default :
         cout << "Invalid choice" << endl;
    }
  } while ( !done );
  cout << "Good Bye !!" << endl;
}
