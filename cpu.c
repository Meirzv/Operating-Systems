#include "oslabs.h"
#include <stdio.h>
#include <string.h>

struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp) {
    if ((current_process.process_id == 0) && (current_process.total_bursttime == 0)) {// NULLPCB , New process priorty
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return PCB new_process;
    }
    else if ( new_process.process_priority >= current_process.process_priority) {
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[queue_cnt] = new_process;
        return PCB current_process;
    }
    else { //New process has lower priorty than current process
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        current_process.remaining_bursttime = current_process.execution_endtime - timestamp;
        current_process.execution_endtime = 0;
        current_process.execution_starttime = 0;
        ready_queue[queue_cnt] = current_process;
        return PCB new_process;
    }
}


void main(){
    struct PCB process_1;
    struct PCB process_2;
    struct PCB process_3;
    
    process_1.process_id = 1;
    process_1.arrival_timestamp = 1;
    process_1.total_bursttime = 5;
    process_1.execution_starttime = 3;
    process_1.execution_endtime = 8;
    process_1.remaining_bursttime = 3;
    process_1.process_priority = 3;
    
    process_2.process_id = 2;
    process_2.arrival_timestamp = 3;
    process_2.total_bursttime = 6;
    process_2.execution_starttime = 6;
    process_2.execution_endtime = 12;
    process_2.remaining_bursttime = 0;
    process_2.process_priority = 2;
    
    process_3.process_id = 3;
    process_3.arrival_timestamp = 5;
    process_3.total_bursttime = 3;
    process_3.execution_starttime = 5;
    process_3.execution_endtime = 8;
    process_3.remaining_bursttime = 3;
    process_3.process_priority = 5;
    
    
}
