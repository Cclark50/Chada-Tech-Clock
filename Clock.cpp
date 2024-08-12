//
// Created by metat on 8/11/2024.
//

#include "Clock.h"
#include <iostream>


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

//adds 1 hour to the clock
void Clock::addOneHour()
{
    if(hours == 23)
    {
        setHours(0);
    }
    else
    {
        setHours(hours + 1);
    }
}

//adds one minute to the clock
void Clock::addOneMinute()
{
    if(minutes == 59)
    {
        addOneHour();
        setMinutes(0);
    }
    else
    {
        setMinutes(minutes + 1);
    }
}

//adds one second to the clock
void Clock::addOneSecond()
{
    if(seconds == 59)
    {
        addOneMinute();
        setSeconds(0);
    }
    else
    {
        setSeconds(seconds + 1);
    }
}
//takes an input a number and turns it into a 2 digit string
std::string Clock::twoDigitString(unsigned int n)
{
    std::string str = "";
    //if we have a number less than 9, it gets a 0 prepended to it
    if(n <= 9)
    {
        str += '0';
    }
    str += std::to_string(n);
    return str;
}

//returns a string of a character entered that is n characters long
std::string Clock::nCharClockString(size_t n, char c)
{
    std::string str = "";
    for(int i = 0; i < n; i++)
    {
        str += c;
    }
    return str;
}

//formats time like a 24 hour clock
std::string Clock::formatTime24(unsigned int h, unsigned int m, unsigned int s)
{
    std::string str = "";
    str += twoDigitString(h);
    str += ':';
    str += twoDigitString(m);
    str += ':';
    str += twoDigitString(s);
    return str;
}

//formats time like a 12 hour clock
std::string Clock::formatTime12(unsigned int h, unsigned int m, unsigned int s)
{
    //0 is midnight 12 is noon
    //if we're under 12 hours, then isPM is a string representing AM
    std::string isPM = "A M";
    //newh is a temporary hold of h to do calculations with
    int newh = h;
    std::string str = "";
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

//displays both the 12 and 24 hour clocks side by side
void Clock::displayClocks()
{
    unsigned int h = hours;
    unsigned int m = minutes;
    unsigned int s = seconds;
    std::cout << nCharClockString(27, '*') << nCharClockString(3, ' ') << nCharClockString(27, '*') << std::endl;
    std::cout << nCharClockString(1, '*') << nCharClockString(6, ' ') << "12-HOUR CLOCK" << nCharClockString(6, ' ') << nCharClockString(1, '*') << nCharClockString(3, ' ');
    std::cout << nCharClockString(1, '*') << nCharClockString(6, ' ') << "24-HOUR CLOCK" << nCharClockString(6, ' ') << nCharClockString(1, '*') << std::endl;
    std::cout << std::endl;
    std::cout << nCharClockString(1, '*') << nCharClockString(6, ' ') << formatTime12(h, m, s) << nCharClockString(7, ' ') << nCharClockString(1, '*') << nCharClockString(3, ' ');
    std::cout << nCharClockString(1, '*') << nCharClockString(8, ' ') << formatTime24(h, m, s) << nCharClockString(9, ' ') << nCharClockString(1, '*') << std::endl;
    std::cout << nCharClockString(27, '*') << nCharClockString(3, ' ') << nCharClockString(27, '*') << std::endl;
}

