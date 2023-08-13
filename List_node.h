#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using namespace std;


class List_node {
public:
    string get_data();
    List_node* get_next();
    void set_data(string data);
    void set_next(List_node* next);
    int get_serv_time(string data);
    string get_item();
private:
    string data;
    List_node* next;
};
