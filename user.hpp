#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class User{
    private:
        int user_id;
        string user_name;
        vector<time_t> clocked_hours;

    public:
        User(int user_id, string user_name);
        User();





};



#endif