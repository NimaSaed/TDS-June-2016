#include <iostream>
#include <cstdlib>
#include "StackP.h"
#include "StackP.cpp"

using namespace std;

// TODO: Write your code here
// Begin Question


double evalPostfixExpression( string str )
{
   char ch;
   double result, operand1, operand2;
   Stack aStack;

   // for each character ch in the string
   int i = 0;
   while ( i < str.length() )
   {
       ch = str[i];
       if ( isdigit(ch) ) // if ch is an operand
       {
           //push ch onto stack
           if (isspace(str[i+1]) ||
               str[i+1] == '*' || str[i+1] == '/' ||
               str[i+1] == '+' || str[i+1] == '-'
              )
           {
               result = ch - '0'; //minus starting character '0'
               aStack.push(result);
               i++;
           }
           else
           {
              if (isdigit(str[i+1]))
              {
                  result = 0;
                  // Convert each digit char and add into result, eg 123
                  while (str[i] >= '0' && str[i] <='9')
                  {
                      result = (result * 10) + (str[i] - '0');
                      i++;
                  }
                  aStack.push(result);
              }
           }
       }
       else
       {
          if ( isspace( ch ) ) i++;
          else
          {
             aStack.getTop(operand2);
             aStack.pop();
             aStack.getTop(operand1);
             aStack.pop();
             switch (str[i])
             {
                case '*':
                       result = operand1 * operand2;
                       break;
                case '/':
                       result = operand1 / operand2;
                       break;
                case '+':
                       result = operand1 + operand2;
                       break;
                case '-':
                       result = operand1 - operand2;
                       break;
                default:
                       cout << "Illegal postfix expression." << endl;
                       exit(1);
             }
             aStack.push(result);
             i++;

          }
       }
   }
   aStack.getTop(result);
   aStack.pop();

   if ( aStack.isEmpty() ) return result;
   else
   {
      cout << "Illegal postfix expression." << endl;
      exit(1);
   }

}

// End Question

int main()
{
   cout << ("ADT Stack Application - Evaluating Postfix Expressions") << endl;

   string postfixExp;
   double result;

   cout << "Enter a postfix expression to be evaluated: ";
   getline(cin, postfixExp);

   result = evalPostfixExpression (postfixExp);

   cout << postfixExp << " = " << result << endl;

   return 0;
}
