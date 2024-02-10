#ifndef DATETIME
#define DATETIME

using namespace std;
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

class Datetime{
    private:
        time_t* datetime;
        tm* tm_datetime;

        static const int MIN_YEAR = 2019;
        static const int MAX_YEAR = 2100;
    public:
        Datetime(int year, int month, int day, int hour, int minute);
        Datetime();
        ~Datetime();

        string get_date();
        string get_time();

        bool isLeapYear(int year);

        // operators
        friend int operator-(Datetime &d1, Datetime &d2);
        friend bool operator==(Datetime &d1, Datetime &d2);
        friend bool operator!=(Datetime &d1, Datetime &d2);
        friend bool operator<(Datetime &d1, Datetime &d2);
        friend bool operator<=(Datetime &d1, Datetime &d2);
        friend bool operator>(Datetime &d1, Datetime &d2);
        friend bool operator>=(Datetime &d1, Datetime &d2);

        friend ostream &operator<<(ostream &outs, Datetime &datetime);
};


#endif