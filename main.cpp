#include <iostream>
#include <limits>
#include <string>
#include "Clock.h"
using namespace std;

/*@Author Christian Clark
 *@Date 7-16-24
 *
 *This program simulates a 12 and 24 hour clock
 *It will print the two clocks side by side, and the user is able to add
 *an hour, minute, or second to it one at a time
 *The program will also ask the user to set the time of the clock at the start
 */

string nCharString(size_t n, char c)
{
    string str = "";
    for(int i = 0; i < n; i++)
    {
        str += c;
    }
    return str;
}

//prints the menu we use to show valid inputs
void printMenu(string strings[], unsigned int numStrings, unsigned int width)
{
    cout << nCharString(width, '*') << endl;
    for(int i = 1; i <= numStrings; i++)
    {
        cout << "* " << i << " - " << strings[i - 1];
        int temp = strings[i - 1].size();
        temp = width - temp - 1 - 6;
        cout << nCharString(temp, ' ') << '*' << endl;
        if(i != numStrings)
        {
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}

//loops to get valid input from user
unsigned int getMenuChoice(unsigned int maxChoice)
{
    int choice;
    do
    {
        try
        {
            cin >> choice;
            if(choice >= 1 && choice <= maxChoice)
            {
                return choice;
            }
            if(cin.fail())
            {
                throw invalid_argument("invalid");
            }
        }
        catch (exception& e)
        {
            choice = 999;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(true);
}


//loops to get and use user input to manipulate the clock
void mainMenu(Clock& clock)
{
    string choiceStrings[4] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    const int NUM_CHOICES = 4;
    int choice;
    bool contprogram = true;
    do
    {
        printMenu(choiceStrings, NUM_CHOICES, 26);
        choice = getMenuChoice(4);
        switch(choice)
        {
        case 1:
            clock.addOneHour();
            clock.displayClocks();
            break;
        case 2:
            clock.addOneMinute();
            clock.displayClocks();
            break;
        case 3:
            clock.addOneSecond();
            clock.displayClocks();
            break;
        case 4:
            contprogram = false;
            break;
        default:
            break;
        }
    }while(contprogram);
}

void getInitialTime(unsigned int& h, unsigned int& m, unsigned int& s)
{
    cout << "Enter clock hours:" << endl;
    do
    {
        cin >> h;
    }while(h > 24);
    cout << "Enter clock minutes:" << endl;
    do
    {
        cin >> m;
    }while(m > 60);
    cout << "Enter clock seconds:" << endl;
    do
    {
        cin >> s;
    }while(s > 60);
}

int main()
{
    //gets the inital hour minute second for the clock and validates input
    unsigned int h, m, s;
    getInitialTime(h, m, s);
    //creates the clock with the user specified time then starts the main menu protocol
    Clock clock(h, m ,s);
    cout << endl;
    mainMenu(clock);
    return 0;
}
