#include "datetime.hpp"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// constructors
Datetime::Datetime(int year, int month, int day, int hour, int minute){
    datetime = time(0);
    
}
Datetime::Datetime(){

}

string Datetime::get_date(){

}
string Datetime::get_time(){

}

// operators
float operator-(Datetime &d1, Datetime &d2);
bool operator==(Datetime &d1, Datetime &d2);
bool operator!=(Datetime &d1, Datetime &d2);
bool operator<(Datetime &d1, Datetime &d2);
bool operator<=(Datetime &d1, Datetime &d2);
bool operator>(Datetime &d1, Datetime &d2);
bool operator>=(Datetime &d1, Datetime &d2);

ostream &operator<<(ostream &outs, Datetime &datetime);