/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

#include <iostream>


using namespace std;

int main(){
	
	double power = 1;
	for (int i = 0 ; i < 50 ; i++)
		power = power * 2;
	
	string str = to_string(power);
	
	int sum = 0;
	for (int i = 0; i<str.length(); ++i){
		char num = str[i];
		sum = sum + (num - '0');	
	}
	
	cout <<str.length()<<endl;
	cout <<power<<" "<< sum;
	
	return 0;
}