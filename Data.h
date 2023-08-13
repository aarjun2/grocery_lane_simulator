#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

class Data
{
public: // Member functions
    Data();
    void set_customerNumber(int& number);
    void set_serviceTime(int& stime);
    void set_totalTime(int& ttime);
    int get_customerNumber();
    int get_serviceTime();
    int get_totalTime();
    ~Data() {
        customerNumber = 0;
        serviceTime = 0;
        totalTime = 0;
    }
private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!

ostream& operator<<(ostream& file, Data& rhs);