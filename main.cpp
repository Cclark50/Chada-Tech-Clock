#include <iostream>
#include <string>
using namespace std;

/*@Author Christian Clark
 *@Date 7-16-24
 *
 *This program simulates a 12 and 24 hour clock
 *It will print the two clocks side by side, and the user is able to add
 *an hour, minute, or second to it one at a time
 *The program will also ask the user to set the time of the clock at the start
 */


//This class holds the hours, minutes, and seconds of the clock
class Clock
{
public:
    //getters and setters
    unsigned int getSeconds(){return seconds;}
    unsigned int getMinutes(){return minutes;}
    unsigned int getHours(){return hours;}
    void setSeconds(unsigned int seconds){this->seconds = seconds;}
    void setMinutes(unsigned int minutes){this->minutes = minutes;}
    void setHours(unsigned int hours){this->hours = hours;}
    //default constructor
    Clock();
    //more useful overloaded constructor
    Clock(unsigned int h, unsigned int m, unsigned int s);
private:
    //variables to hold said hours minutes seconds
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
};

Clock::Clock()
{
    seconds = 0;
    minutes = 0;
    hours = 0;
}

Clock::Clock(unsigned int h, unsigned int m, unsigned int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

//takes an input a number and turns it into a 2 digit string
string twoDigitString(unsigned int n)
{
    string str = "";
    //if we have a number less than 9, it gets a 0 prepended to it
    if(n <= 9)
    {
        str += '0';
    }
    str += to_string(n);
    return str;
}

//returns a string of a character entered that is n characters long
string nCharString(size_t n, char c)
{
    string str = "";
    for(int i = 0; i < n; i++)
    {
        str += c;
    }
    return str;
}

//formats time like a 24 hour clock
string formatTime24(unsigned int h, unsigned int m, unsigned int s)
{
    string str = "";
    str += twoDigitString(h);
    str += ':';
    str += twoDigitString(m);
    str += ':';
    str += twoDigitString(s);
    return str;
}

//formats time like a 12 hour clock
string formatTime12(unsigned int h, unsigned int m, unsigned int s)
{
    //0 is midnight 12 is noon
    //if we're under 12 hours, then isPM is a string representing AM
    string isPM = "A M";
    //newh is a temporary hold of h to do calculations with
    int newh = h;
    string str = "";
    //above or equal to 12 hours then we have isPM set to PM instead
    if(h >= 12)
    {
        isPM = "P M";
        newh = h - 12;
    }
    //if we're at 12 either am or pm, append 12 to the string
    if(newh == 0)
    {
        str += "12";
    }
    else
    {
        str += twoDigitString(newh);
    }

    str = str + ':' + twoDigitString(m) + ':' + twoDigitString(s) + ' ' + isPM;

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
       cin >> choice;
    }while(choice <= 0 || choice > maxChoice);
    return choice;
}

//displays both the 12 and 24 hour clocks side by side
void displayClocks(Clock& clock)
{
    unsigned int h = clock.getHours();
    unsigned int m = clock.getMinutes();
    unsigned int s = clock.getSeconds();
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

//adds 1 hour to the clock
void addOneHour(Clock& clock)
{
    unsigned int hours = clock.getHours();
    if(hours == 23)
    {
        clock.setHours(0);
    }
    else
    {
        clock.setHours(hours + 1);
    }
}

//adds one minute to the clock
void addOneMinute(Clock& clock)
{
    unsigned int minutes = clock.getMinutes();
    if(minutes == 59)
    {
        addOneHour(clock);
        clock.setMinutes(0);
    }
    else
    {
        clock.setMinutes(minutes + 1);
    }
}

//adds one second to the clock
void addOneSecond(Clock& clock)
{
    unsigned int second = clock.getSeconds();
    if(second == 59)
    {
        addOneMinute(clock);
        clock.setSeconds(0);
    }
    else
    {
        clock.setSeconds(second + 1);
    }
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
            addOneHour(clock);
            displayClocks(clock);
            break;
        case 2:
            addOneMinute(clock);
            displayClocks(clock);
            break;
        case 3:
            addOneSecond(clock);
            displayClocks(clock);
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
