/*
 Exercise 01:
 Numbers below 10 are {1,2,3,4,5,6,7,8,9}, multiples of 3 and 5 in this group are {3,5,6,9} and sum of them is 23.
 
 find sum of all the multiples 3 and 5 below 1000. (The first 2 with correct answer has 1 point bones)
*/
#include <iostream>

using namespace std;


int main(){
    int sum = 0;
    for (int i = 1 ; i<1000 ; i++){
        if (i%3 == 0 || i%5 == 0){
                sum += i;
        }
    }
    cout << sum;
    return 0;
}
