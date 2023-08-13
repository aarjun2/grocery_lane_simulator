#include "List_node.h"
/**********
function: getter and setter fucntions to initialzie data and access data
Date created: 3/19/2022
Date last modified:3/19/2022, 3/20/2022, 3/21/2022
Description: its a constructor that initializes value for the private variables
Input parameters: none
Returns: none
preconditions:data must be inputted, the order must generate the amount of numbers as size
postconditions: if executed right, the values will be set through
the set functions and can be accessed through the get functions
**/
string List_node::get_data() {
    return this->data;
}

List_node* List_node::get_next() {
    return this->next;
}

void List_node::set_data(string data) {
    this->data = data;
}

void List_node::set_next(List_node* next) {
    this->next = next;
}
// assigned a time for different grocery items based on the item, return an integer time based on the string
int List_node::get_serv_time(string data) {
    if (data == "apple") {
        return 5;
    }
    if (data == "cereal") {
        return 4;
    }
    if (data == "milk") {
        return 3;
    }
    if (data == "banana") {
        return 2;
    }
    if (data == "candy") {
        return 1;
    }
    return 0;
}
//randomly generates a number to see which item a person has in their bag and returns the string to the node
string List_node::get_item() {
    //srand(time(NULL));
    std::random_device rd;
    std::srand(rd());
    int item_generated = rand() % 5 + 1;
    string item_return = "";
    if (item_generated == 1) {
        item_return = "apple";
    }
    if (item_generated == 2) {
        item_return = "cereal";
    }
    if (item_generated == 3) {
        item_return = "milk";
    }
    if (item_generated == 4) {
        item_return = "banana";
    }
    if (item_generated == 5) {
        item_return = "candy";
    }
    return item_return;
}