#include "Data.h"
#include "linkedlist.h"

class QueueNode
{
public:
    QueueNode();
    void set_pData(Data* data);
    void set_pNext(QueueNode* next);
    Data* get_data();
    QueueNode* get_next();
    List_node* get_link_head();
    void set_link_head(List_node* head);
    void create_list();
    int compute_servicetime();
    ~QueueNode();
private:
    Data* pData;    // The memory for Data will need to be allocated on the heap as well!
    QueueNode* pNext;
    List_node* link_head;
};
