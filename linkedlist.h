#include "List_node.h"

class linked_list {
private:
    List_node* head;
public:
    linked_list() {
        head = NULL;
    }
    List_node* make_node();
    void insert_head();
    List_node* get_head();
    void set_head(List_node* ptr);
    // destructor
    ~linked_list() {
        head = NULL;
    }
};