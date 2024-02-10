#include "user.hpp"
using namespace std;



User::User(int id, string username) : hours_worked(0), hours_overtime(0), hours_statutory(0),days_worked(0){
    // TODO: how to handle same id for users in database
    if(id < 0)
        throw "invalid id";

    this->id = id;
    this->username = username;
    this->missing_time = true;

    // TODO: add times into vector 

    // if no missing times set missing_time to false 
    // & calculate the hours 

}

User::User(){ 
    // TODO: default user to put into database
 }
User::~User(){ }


int User::get_id(){ return id; }
string User::get_username(){ return username; }
float User::get_hours_worked(){ return hours_worked; }
float User::get_hours_overtime(){ return hours_overtime; }
float User::get_hours_statutory(){ return hours_statutory; }

