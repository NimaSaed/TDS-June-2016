#include <iostream>
#include "StackP.h"
#include "StackP.cpp"

using namespace std;

bool balancedBraces(const string & input)
{
    Stack aStack;
    bool balancedSoFar = true;
    int i = 0;

    while ( balancedSoFar && i<input.length() )
    {
        char ch = input[i];
        ++i;

        //push an open brace
        if (ch == '{')
        {
            aStack.push('{');
        }

        // close brace
        else if (ch == '}')
        {
            if (!aStack.isEmpty())
            {
                aStack.pop();  // pop a matching open brace
            }
            else
            {
                balancedSoFar = false;
                break;
            }
        }
    }

    if (balancedSoFar && aStack.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    bool balancedSoFar = false;

    cout << "Input a string: ";
    cin >> input;

    balancedSoFar = balancedBraces(input);

    if (balancedSoFar)
    {
        cout << "Result: The above string is balanced" << endl;
    }
    else
    {
        cout << "Result: The above string is not balanced" << endl;
    }

    return 0;
}
