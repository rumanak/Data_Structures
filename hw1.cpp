/*
 * Input a dollar amount for a check
 * Author: Rumana Khan
 * Last Modified: 1/28/2020
 * Known Bug: N/A
 */

#include <iostream>
#include <string.h>
#include <cctype>
using namespace std; 

    string one[] = { "", "one ", "two ", "three ", "four ", "five ", "six ",
                     "seven ", "eight ", "nine ", "ten ", "eleven ", 
                     "twelve ", "thirteen ", "fourteen ", "fifteen ", 
                     "sixteen ", "seventeen ", "eighteen ", "nineteen "
                   };

    string ten[] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", 
                    "sixty ", "seventy ", "eighty ", "ninety "
                   };
/*
 * Checks if the input is valid or not
 * @param int d: one int variable
 * @precondition: paramater d is the dollar amount
 * @postcondition:1 or 0 is outputed
 */
bool check (int d);
/* Checks if the cents make sense
 * @param int c: one int variable
 * @precondition: paramater c is the cent amount
 * @postcondition:1 or 0 is outputed
 */
bool chk (int c);

/* Returns the dollar amount in words for LESS THAN 19
 * @param int n, string s: one int and one string
 * @precondition:int n is taken from other function
 * @postcondition:returns the correct words from string one and ten
 */
string num_word(int n, string s);

/*Converts the dollar amount in words FOR MORE THAN 19
 *@param int n, one int variable
 *@precondition: int n is assigned
 *@postcondition: Converts for thousands and hundreds, etc...
 */
string convert(int n);

int main ()
{
    int dollar;
    char dot;
    int cents;
    char ans;

    do 
    {
        cout << "Enter a dollar amount:$"; 
        cin >> dollar >> dot >> cents;
    
        if ((check(dollar)) && (chk(cents)))
        {
            cout << "It's " << convert(dollar);
            cout << "and " << cents << "/100" << endl;
        }
        cout << "Do it again? Y/N:";
        cin >> ans;
   
    } while ((ans == 'y') || (ans == 'Y'));
    
    cout << "Bye!" << endl;

    return 0;
}

//check's dollar amount for errors
bool check (int d)
{
    if (d > 9999)
    {
        cout << "Too big of a input!" << endl;
        return 0;
    }
    else if (d < 0)
    {
        cout << "CAN NOT BE NEGATIVE!!!" << endl;
        return 0;
    }
    else if (cin.fail())
    {
        cout << "Wrong input types." << endl;
        cin.clear();
        cin.ignore(2048, '\n');
        return 0;
    }
    else
        return 1;
}
//check's cents for errors
bool chk (int c)
{ 

    if (c < 0) 
    {   
        cout << "Too many digits for cents!!!" << endl;
        return 0;
    }
    else if (c > 99)
    {
        cout << "Too many digits for cents!!!" << endl;
        return 0;
    } 
    else 
        return 1;
}
//converts dollar to word for smaller amounts
string num_word(int n, string s)
{
    string str = "";
    if (n > 19)
        str += ten[n/10] + one[n%10];
    else 
        str += one[n];
    return str;
}
//converts dollar to word + adds and 
string convert(int n)
{
    string output;

    output += num_word(((n/1000) % 100), "");
    if (n > 999)
        output += "thousand ";

    output += num_word(((n/100) % 10), "");
    if ((n/100) % 10)
        output += "hundred ";

    if (n > 100 && n % 100)
        output += "and ";

    output += num_word((n%100), "");

    return output;
}

