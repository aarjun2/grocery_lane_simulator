#include "Queue.h"
/**********
function: enqueue: adds items from the tail, dequeue: deletes item from the head, is empty: if head is null
returns 1 meaning its empty, print queue: prints the entire queue
Date created: 3/19/2022
Date last modified:3/19/2022, 3/20/2022, 3/21/2022
Description: its a constructor that initializes value for the private variables
Input parameters: none
Returns: none
preconditions:data must be inputted, the order must generate the amount of numbers as size
postconditions: if executed right, this will create a queue, that will be modified based on customers entering
and they get dequeued when their service time is done, and prints the customers every 10 mins
**/
QueueNode* Queue::make_node(Data* value) {
    QueueNode* node = new QueueNode;
    node->set_pData(value);
    node->set_pNext(NULL);
    return node;
}

void Queue::enqueue(Data* value) {
    QueueNode* node = new QueueNode;
    node->set_pNext(NULL);
    node->create_list();
    int service_time = node->compute_servicetime();
    value->set_serviceTime(service_time);
    int total_time = value->get_totalTime();
    total_time = total_time + service_time;
    value->set_totalTime(total_time);
    node->set_pData(value);

    if (pTail == NULL) {
        pHead = pTail = node;
        return;
    }
    pTail->set_pNext(node);
    pTail = node;
}

void Queue::enqueue_express(Data* value) {
    QueueNode* node = new QueueNode;
    node->set_pNext(NULL);
    node->create_list();
    int service_time = node->compute_servicetime();
    value->set_serviceTime(service_time);
    int total_time = value->get_totalTime();
    total_time = total_time + service_time;
    value->set_totalTime(total_time);
    node->set_pData(value);

    if (pTail == NULL) {
        pHead = pTail = node;
        return;
    }
    pTail->set_pNext(node);
    pTail = node;
}

void Queue::dequeue() {
    if (pHead == NULL) {
        return;
    }
    QueueNode* temp = pHead;
    pHead = pHead->get_next();
    if (pHead == NULL) {
        pTail = NULL;
    }
    Data* tmpData = temp->get_data();
    if (temp != NULL)
    {
        cout << endl;
        cout << "customer is in service lane" << endl;
        cout << "customer number: " << temp->get_data()->get_customerNumber() << endl;
        cout << "Total time: " << temp->get_data()->get_totalTime() << endl;
        if (tmpData != NULL) {
            delete(tmpData);
        }
        delete(temp);
    }
}

void Queue::dequeue_express() {
    if (pHead == NULL) {
        return;
    }
    QueueNode* temp = pHead;
    pHead = pHead->get_next();
    if (pHead == NULL) {
        pTail = NULL;
    }
    Data* tmpData = temp->get_data();
    if (temp != NULL)
    {
        cout << endl;
        cout << "customer is in express lane" << endl;
        cout << "customer number: " << temp->get_data()->get_customerNumber() << endl;
        cout << "Total time: " << temp->get_data()->get_totalTime() << endl;
        if (tmpData != NULL) {
            delete(tmpData);
        }
        delete(temp);
    }
}

void Queue::print_queue() {
    if ((isEmpty() == 1) && (pTail = NULL)) {
        cout << "queue is empty" << endl;
        return;
    }
    QueueNode* temp = pHead;
    while (temp != NULL) {
        Data tempdata;
        tempdata = *(temp->get_data());
        cout << tempdata << endl;
        temp = temp->get_next();
    }
}

int Queue::isEmpty() {
    if (pHead == NULL) {
        return 1;
    }
    return 0;
}

Queue::Queue() {
    pHead = NULL;
    pTail = NULL;
}

QueueNode* Queue::get_head() {
    return pHead;
}