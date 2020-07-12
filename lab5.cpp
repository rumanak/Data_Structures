//Program to check for balanced parentheses 
//Name:Rumana Khan 
//Date: 4/6/2020
//Known Bugs: N/A

#include<iostream>
#include<stack>
using namespace std;

/* 
 * Checks whether the parenthesis is balanced
 * @param string check: one string variable
 * @precondition: parameter check is to be checked
 * @postcondition: 1 or 0 is outputed
 */
bool check (string check);

int main()
{
    //Test 1
    string s = "()()]";
    cout << s << endl;
    if (check(s))
        cout << "THIS IS BALANCED!" << endl;
    else 
        cout << "This is not balanced. Try again!" << endl;

    //Test 2
    string two  = "{[()(})";
    cout << two << endl;
    if (check(two))
        cout << "THIS IS BALANCED!" << endl;
    else 
        cout << "This is not balanced. Try again!" << endl;

    //Test 3
    string three = "[()]{}";
    cout << three << endl;
    if (check(three))
        cout << "THIS IS BALANCED!" << endl;
    else 
        cout << "This is not balanced. Try again!" << endl;

    //Test 4
    string four = "{[()()]{}}";
    cout << four << endl;
    if (check(four))
        cout << "THIS IS BALANCED!" << endl;
    else 
        cout << "This is not balanced. Try again!" << endl;

}

//Checks whether the string of parenthesis is balanced
bool check (string check)
{
    stack <char> stck;

    //Checks the expression
    for (int i = 0; i < check.length(); i++)
    {
        char x = check[i];
        
        //if open PUSH
        if ((x == '(') || (x == '{') || (x == '['))
            stck.push(x);

        //if closed and matched POP
        else if (x == ')')      
        {
            if (stck.empty())
                return false;
            else if (stck.top() == '(')
                stck.pop();
            else 
                return false;
        }
        else if (x == '}')      
        {
            if (stck.empty())
                return false;
            else if (stck.top() == '{')
                stck.pop();
            else 
                return false;
        }
        else if (x == ']')      
        {
            if (stck.empty())
                return false;
            else if (stck.top() == '[')
                stck.pop();
            else 
                return false;
        }
        //do nothing
        else 
            cout << "";
    }

}
