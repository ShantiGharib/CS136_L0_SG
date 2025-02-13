// Shanti Gharib
// Lab #0
#include <iostream>
#include <string>
using namespace std;
void Cout_number_input_helper( int number_idx, int &num );
int main()
{
    int num1 = 0, num2 = 0, sum = 0;

    cout << "\nMy name is  " << "Shanti Gharib\n";
    /*asks user to enter the nth number, then assigns
        the number to the nth number's corresponding variable*/
    Cout_number_input_helper( 1, num1 );
    Cout_number_input_helper( 2, num2 );

    sum = num1 + num2;
    cout << "\nThe sum of " << num1 << " and " << num2 << " is " << sum << ".\n";
    return 0;
}
void Cout_number_input_helper( int number_idx, int &num ) {
    const string standard_message = "\nEnter number " + to_string( number_idx ) + ": ";
    const string error_message = "\nThe previous entered number was not a valid integer.\nPlease re-enter the number again: ";
    string temp = "";
    
    bool valid = 1;
    do {
        cout << ( !valid ? error_message : standard_message );
        getline( cin, temp );
        
        int idx = ( !temp.empty() && temp[0] == '-' );
        while ( idx < temp.size() && isdigit( temp[idx] ) ) ++idx;
        valid = ( idx == temp.size() );

    } while ( !valid );

    num = stoi( temp );
}
/*
  PROGRAM OUTPUTS (6 cases):
   //case 1: two negative values
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: -5

    Enter number 2: -13

    The sum of -5 and -13 is -18.

    -------------------------------
   case 2: one negative value and one positive value
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: -5

    Enter number 2: 25

    The sum of -5 and 25 is 20.

    -------------------------------
   case 3: two positive values
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: 5

    Enter number 2: 7

    The sum of 5 and 7 is 12.

    -------------------------------
   case 4: NaN and a number
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: =-6

    The previous entered number was not a valid integer.
    Please re-enter the number again: -6

    Enter number 2: 4

    The sum of -6 and 4 is -2.

    -------------------------------
   case 5: number and (NaN followed by a number with more than one digit)
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: 7

    Enter number 2: =6

    The previous entered number was not a valid integer.
    Please re-enter the number again: 56

    The sum of 7 and 56 is 63.

    -------------------------------
   case 6: NaN and non-integers
    -------------------------------

    My name is  Shanti Gharib

    Enter number 1: /4560

    The previous entered number was not a valid integer.
    Please re-enter the number again: 4560

    Enter number 2: 4560.002

    The previous entered number was not a valid integer.
    Please re-enter the number again: 4561

    The sum of 4560 and 4561 is 9121.

    -------------------------------
*/
