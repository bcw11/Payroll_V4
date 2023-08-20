#include <iostream>
#include <vector>
#include "user.hpp"
#include <ctime>
using namespace std;


int main(){
    tm time{};
    time.tm_year = 2023-1900;
    time.tm_mday = 1;

    tm time2{};
    time2.tm_year = 2023-1900;
    time2.tm_mday = 1;
    time.tm_hour = 1;

    mktime(&time);
    mktime(&time2);
    cout<<asctime(&time)<<endl;
    cout<<asctime(&time2)<<endl;

    double diff = difftime(mktime(&time),mktime(&time2));
    cout<<diff<<endl;


    return 0;
}
    // time_t current_time = time(0);
    // tm* bruh = localtime(&current_time);

    // cout<<current_time<<endl;

    // cout<<1900+ bruh->tm_year<<endl;

    // bruh->tm_year = 100;

    // cout<<1900+ bruh->tm_year<<endl;
    

    // // char* dt = ctime(&current_time);
    // // cout << "The current local date and time is: " << dt << endl;
    
    // // tm *gmt_time = gmtime(&current_time);
    // // dt = asctime(gmt_time);
    // // cout << "The current UTC date and time is:"<< dt << endl;