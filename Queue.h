#include "Queuenode.h"

class Queue
{
public: // Member functions
    Queue();
    void enqueue(Data* value);
    void enqueue_express(Data* value);
    void dequeue();
    void dequeue_express();
    QueueNode* make_node(Data* value);
    void print_queue();
    QueueNode* get_head();
    int isEmpty();
    ~Queue() {
        pHead = NULL;
        pTail = NULL;
    }
private:
    QueueNode* pHead;
    QueueNode* pTail;
};
