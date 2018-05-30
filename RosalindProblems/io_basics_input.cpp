#include <iostream>
using namespace std;


int main()
{
    // declare variables
    int usr_inp2;
    int usr_inp;

    // get user input
    cout << "Input a number:\n";
    cin >> usr_inp;
    usr_inp2 = 4*usr_inp;

    // display stuff
    cout << "The number you entered is ";
    cout << usr_inp << " and four times your number is " << usr_inp2;

    return 0;
}
