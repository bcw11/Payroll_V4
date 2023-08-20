#ifndef DATETIME
#define DATETIME

using namespace std;
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

class Datetime{
    private:
        time_t datetime;
    public:
        Datetime(int year, int month, int day, int hour, int minute);
        Datetime();

        string get_date();
        string get_time();

        // operators
        friend float operator-(Datetime &d1, Datetime &d2);
        friend bool operator==(Datetime &d1, Datetime &d2);
        friend bool operator!=(Datetime &d1, Datetime &d2);
        friend bool operator<(Datetime &d1, Datetime &d2);
        friend bool operator<=(Datetime &d1, Datetime &d2);
        friend bool operator>(Datetime &d1, Datetime &d2);
        friend bool operator>=(Datetime &d1, Datetime &d2);

        friend ostream &operator<<(ostream &outs, Datetime &datetime);
};


#endif