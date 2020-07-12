/*
 * Main file for Lab#3
 * Name: Rumana Khan 
 * Date Last Modified: 2/17/2020\
 * Known Bug: N/A
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "UnsortedType.h"

using namespace std;

int main()
{
    char ans;
    int choice;
    int month;
    int day;
    int year;
    bool t;
    string d;
    bool repeat;

    UnsortedType B(10);

    cout << "Welcome to the Appointment Book!" << endl;

    do 
    {
        cout << "Please enter a command using the given numbers" << endl;
        cout << "Display[1] Add[2] Search[3] Delete[4]" << endl;
        cin >> choice; 
        if (choice == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                // this does not work 
                // it causes an error 
                //cout << B.list[i]; or B.info[i];
            }
        }
        else if (choice == 2)
        {
            cout << "Please enter the month. ";
            cin >> month;
            cout << "Day. ";
            cin >> day;
            cout << "Year. ";
            cin >> year;
            cout << "Description. ";
            cin >> d;

            Appointment A(month,day,year,d);
            B.PutItem(A);
        }

        else if (choice == 3)
        {
            cout << "Please enter the month you are searching for. ";
            cin >> month;
            cout << "Day ";
            cin >> day;
            cout << "Year ";
            cin >> year;
            cout << "Description. ";
            cin >> d;
            
            Appointment C(month,day,year,d);

            B.GetItem(C, t);

        }
        else if (choice == 4)
        {
            cout << "Please enter the month you are trying to delete.";
            cin >> month;
            cout << "Day ";
            cin >> day;
            cout << "Year ";
            cin >> year;
            cout << "Description. ";
            cin >> d;
            
            Appointment D(month,day,year,d);

            B.DeleteItem(D);

        }
       
        cout << "Would you like to quit? y/n" << endl;
        cin >> ans;

        if ((ans == 'n') || (ans == 'N'))
        {
            repeat = 1;
        }

    }while(repeat); 

    return 0;
}
