
#include "test.h"

int main(void) {
    Queue normal_lane;
    Queue express_lane;
    
    int n = 0, arrival_time_service = 0, service_time = 0, flag_service = 0;
    int arrival_time_express = 0, service_time_express = 0, flag_express = 0;
    cout << "enter minutes to test" << endl;
    cin >> n;
    int custNo = 0, express_custNo = 0;
    // treating the first node separately
    int iter = 0;
    int nTotaltime = 0;
    int servTime = 0;
    Data* normal_data = NULL;
    //data for express
    int express_nTotaltime = 0;
    int express_servTime = 0;
    Data* express_normal_data = NULL;

    srand(time(NULL));
    arrival_time_service = rand() % 6 + 3;
    arrival_time_express = rand() % 5 + 1;

    for (; iter <= n; iter++) {
        //if arrival time is zero then enqueue
        if (arrival_time_service == 0) {
            normal_data = new Data;
            if (normal_data != NULL) {
                custNo++;
                normal_data->set_customerNumber(custNo);
                normal_data->set_totalTime(nTotaltime);
                normal_lane.enqueue(normal_data);
                service_time = normal_data->get_serviceTime();
                nTotaltime = nTotaltime + service_time;
                arrival_time_service = rand() % 6 + 3;
            }
        }
        // always get head's service time and dequeue
        QueueNode* pHead;
        pHead = normal_lane.get_head();
        if (pHead != NULL) {
            Data* node_data = pHead->get_data();
            if (flag_service == 0) {
                servTime = node_data->get_serviceTime();
                flag_service = 1;
            }
            servTime--;
            if (servTime == 0) {
                normal_lane.dequeue();
                flag_service = 0;
            }
        }
        
        // handle express lane 
        //if arrival time is zero then enqueue
        if (arrival_time_express == 0) {
            express_normal_data = new Data;
            if (express_normal_data != NULL) {
                express_custNo++;
                express_normal_data->set_customerNumber(express_custNo);
                express_normal_data->set_totalTime(express_nTotaltime);
                express_lane.enqueue_express(express_normal_data);
                service_time_express = express_normal_data->get_serviceTime();
                express_nTotaltime = express_nTotaltime + service_time_express;
                arrival_time_express = rand() % 5 + 1;
            }
        }
        // always get head's service time and dequeue
        pHead = express_lane.get_head();
        if (pHead != NULL) {
            Data* node_data = pHead->get_data();
            if (flag_express == 0) {
                express_servTime = node_data->get_serviceTime();
                flag_express = 1;
            }
            express_servTime--;
            if (express_servTime == 0) {
                express_lane.dequeue_express();
                flag_express = 0;
            }
        }
        if (iter % 10 == 0) {
            cout << endl;
            cout << "normal queue start____" << endl;
            normal_lane.print_queue();
            cout << "normal queue end____" << endl;
            cout << endl;
            cout << "express queue start____" << endl;
            express_lane.print_queue();
            cout << "express queue end____" << endl;
        }
        arrival_time_service--;
        arrival_time_express--;
    }
    cout << endl;
    cout << "testing function____________" << endl;
    test mytest;
    mytest.test1_enqueue_empty();
    mytest.test2_enqueue_one_node();
    mytest.test4_dequeue_two_node();
    mytest.test3_dequeue_one_node();
    mytest.test5_24hrs();

	return 0;
}










