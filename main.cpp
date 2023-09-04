#include <iostream>
#include <vector>
#include "user.hpp"
#include "datetime.hpp"
#include <ctime>
using namespace std;


int main(){
    
    Datetime t(2020,7,21,1,40);
    string t_date = t.get_date();
    cout<<t_date<<endl;

    Datetime g(2020,2,29,1,40);
    string t_date_next = t.get_date();
    cout<<t_date_next<<endl;


    return 0;
}