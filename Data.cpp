#include "Data.h"
/**********
function: constructor: initialzies value, overloaded operator to print values, and destructor to reset
values to 0
Date created: 3/19/2022
Date last modified:3/19/2022, 3/20/2022, 3/21/2022
Description: its a constructor that initializes value for the private variables
Input parameters: none
Returns: none
preconditions:data must be inputted, the order must generate the amount of numbers as size
postconditions: if executed right, this will initialize the variables to 0, the values will be set through
the set functions and can be accessed through the get functions, and finally overloaded stream operators
for better printing
**/
Data::Data() {
    customerNumber = 0;
    serviceTime = 0;
    totalTime = 0;
}

void Data::set_customerNumber(int& customerNumber) {
    this->customerNumber = customerNumber;
}
void Data::set_serviceTime(int& stime) {
    this->serviceTime = stime;
}
void Data::set_totalTime(int& ttime) {
    this->totalTime = ttime;
}
int Data::get_customerNumber() {
    return customerNumber;
}
int Data::get_serviceTime() {
    return serviceTime;
}
int Data::get_totalTime() {
    return totalTime;
}
ostream& operator<<(ostream& file, Data& rhs) {
    file << "Customer number: " << rhs.get_customerNumber() << endl;
    file << "Service time: " << rhs.get_serviceTime() << endl;
    file << "Total time:" << rhs.get_totalTime() << endl;
    return file;
}