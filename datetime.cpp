#include "datetime.hpp"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// datetime may change depending on OS

// constructors
Datetime::Datetime(int year, int month, int day, int hour, int minute){
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    datetime = new time_t;
    tm_datetime = localtime(datetime);

    // setting year 
    if (MIN_YEAR <= year && year <= MAX_YEAR)
        tm_datetime->tm_year = year - 1900;
    else{
        throw invalid_argument("(Datetime::Datetime) Invalid year: " + to_string(year));
    }

    // setting month
    if (1 <= month && month <= 12)
        tm_datetime->tm_mon = month - 1;
    else{
        throw invalid_argument("(Datetime::Datetime) Invalid month: " + to_string(month));
    }

    // check if day is within valid range for given month
    if (1 <= day && day <= month_days[month - 1])
        tm_datetime->tm_mday = day;
    // check for valid leap year days
    else if (month == 2 && day <= 29 && isLeapYear(year))
        tm_datetime->tm_mday = day;
    else{
        ostringstream oss;
        oss << "Error(Datetime::Datetime): date = " << year << "-" << month << "-" << day;
        throw invalid_argument(oss.str());
    }

    // setting hour
    if (0 <= hour && hour <= 23)
        tm_datetime->tm_hour = hour;
    else{
        throw invalid_argument("(Datetime::Datetime) Invalid hour: " + to_string(hour));
    }

    // setting minutes
    if (0 <= minute && minute <= 59)
        tm_datetime->tm_min = minute;
    else{
        throw invalid_argument("(Datetime::Datetime) Invalid minute: " + to_string(minute));
    }

    // seconds are not considered in this program
    tm_datetime->tm_sec = 0;

    // convert tm to time_t
    *datetime = mktime(tm_datetime);
}
Datetime::Datetime() {}
Datetime::~Datetime() { delete datetime; }
// TODO: need copy constructor

// TODO: need to set date 
string Datetime::get_date(){
    char date_chr[32];
    strftime(date_chr, sizeof(date_chr), "%Y-%b-%d", tm_datetime);

    return date_chr;
}
string Datetime::get_time(){
    char time_chr[32];
    strftime(time_chr, sizeof(time_chr), "%H:%M", tm_datetime);

    return time_chr;
}

bool Datetime::isLeapYear(int year){

    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// operators
int operator-(Datetime &d1, Datetime &d2){
    return *d1.datetime - *d2.datetime; // in seconds
}
bool operator==(Datetime &d1, Datetime &d2) { return *d1.datetime == *d2.datetime; }
bool operator!=(Datetime &d1, Datetime &d2) { return *d1.datetime != *d2.datetime; }
bool operator<(Datetime &d1, Datetime &d2) { return *d1.datetime < *d2.datetime; }
bool operator<=(Datetime &d1, Datetime &d2) { return *d1.datetime <= *d2.datetime; }
bool operator>(Datetime &d1, Datetime &d2) { return *d1.datetime > *d2.datetime; }
bool operator>=(Datetime &d1, Datetime &d2) { return *d1.datetime >= *d2.datetime; }

ostream &operator<<(ostream &outs, Datetime &d){
    char datetime_chr[32];
    strftime(datetime_chr, sizeof(datetime_chr), "%Y-%b-%d %H:%M (%a)", d.tm_datetime);

    return outs << datetime_chr << endl;
}

// #if defined(_WIN32)

// #elif __APPLE__

// #else

// #endif