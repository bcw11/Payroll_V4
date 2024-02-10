#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "datetime.hpp"
using namespace std;

class User{
    private:
        int id;
        string username;
        vector<time_t> clocked_hours;

        float hours_worked;
        float hours_overtime;
        float hours_statutory;
        int days_worked;

        void insert_clocked_hour(Datetime& datetime);
        // where to put check 
    
        void print_clocked();

    public:
        User(int id, string username);
        User();

        int get_id();
        string get_username();
        float get_hours_worked();
        float get_hours_overtime();
        float get_hours_statutory();

        bool missing_time;
};



#endif