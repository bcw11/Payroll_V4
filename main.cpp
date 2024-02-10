#include <iostream>
#include <vector>
#include "user.hpp"
#include "datetime.hpp"
#include <ctime>
using namespace std;

int main(){

    Datetime t(2010, 7, 21, 1, 20);

    Datetime g(2020, 7, 21, 1, 21);

    // test subtract time

    cout<<t-g;


    // NOTES: 
    // don't need a time diff function, subtract returns seconds
    // TODO: add toggle for daylight savings - maybe calculate it automatically? 

    return 0;
}