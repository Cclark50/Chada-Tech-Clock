//
// Created by metat on 8/11/2024.
//

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

//test comment

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
    void addOneHour();
    void addOneMinute();
    void addOneSecond();
    void displayClocks();
    std::string formatTime12(unsigned int h, unsigned int m, unsigned int s);
    std::string formatTime24(unsigned int h, unsigned int m, unsigned int s);
    std::string nCharClockString(size_t n, char c);
    std::string twoDigitString(unsigned int n);
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




#endif //CLOCK_H
