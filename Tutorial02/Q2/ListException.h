#ifndef LISTEXCEPTION
#define LISTEXCEPTION


#include <stdexcept>
#include <string>

using namespace std;

class ListException : public logic_error
{
public:
   ListException(const string & message = "")
      : logic_error(message.c_str())
   { }  // end constructor
}; // end ListException

#endif
