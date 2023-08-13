#include "linkedlist.h"
/**********
function: constructor: make node to create node, insert head to insert in order, sets and gets the value of head
values to 0
Date created: 3/19/2022
Date last modified:3/19/2022, 3/20/2022, 3/21/2022
Description: its a constructor that initializes value for the private variables
Input parameters: none
Returns: none
preconditions:data must be inputted, the order must generate the amount of numbers as size
postconditions: if executed right, this will set the next to null, get data and store it as a string, gives
access to private member head
**/
List_node* linked_list::make_node() {
    List_node* node = new List_node;
    string data = "";
    data = node->get_item();
    node->set_data(data);
    node->set_next(NULL);
    return node;
}

void linked_list::insert_head() {
    List_node* new_node = make_node();
    new_node->set_next(head);
    head = new_node;
}

List_node* linked_list::get_head() {
    return head;
}

void linked_list::set_head(List_node* ptr) {
    head = ptr;
}