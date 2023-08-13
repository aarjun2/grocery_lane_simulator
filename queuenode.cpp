#include "Queuenode.h"

QueueNode::QueueNode() {
    pData = NULL;
    pNext = NULL;
    link_head = NULL;
}
void QueueNode::set_pData(Data* data) {
    this->pData = data;
}
void QueueNode::set_pNext(QueueNode* next) {
    this->pNext = next;
}
Data* QueueNode::get_data() {
    return pData;
}
QueueNode* QueueNode::get_next() {
    return pNext;
}

List_node* QueueNode::get_link_head() {
    return this->link_head;
}
void QueueNode::set_link_head(List_node* head) {
    this->link_head = head;
}

void QueueNode::create_list() {
    // deciding the number of nodes to add
    //srand(time(NULL));
    std::random_device rd;
    std::srand(rd());
    int number_nodes = rand() % 5 + 1;
    for (int i = 0; i < number_nodes; i++) {
        List_node* node = new List_node;
        string item_name = "";
        item_name = node->get_item();
        node->set_data(item_name);
        node->set_next(NULL);
        if (link_head == NULL) {
            link_head = node;
        }
        else {
            node->set_next(link_head);
            link_head = node;
        }
    }
}

int QueueNode::compute_servicetime() {
    int total_service_time = 0;
    List_node* temp = NULL;
    temp = link_head;
    string test_data = "";
    while (temp != NULL) {
        test_data = temp->get_data();
        total_service_time = total_service_time + temp->get_serv_time(test_data);
        temp = temp->get_next();
    }
    return total_service_time;
}

QueueNode::~QueueNode() {
    pData = NULL;
    pNext = NULL;
    List_node* temp = NULL;
    temp = link_head;
    while (temp != NULL) {
        List_node* del = temp;
        temp = temp->get_next();
        if (del != NULL) {
            free(del);
        }
    }
    link_head = NULL;
}