/*****************************************************************
* @file pinfo.c
* @brief Prints information for process priority and scheduling
* policy for current or given process ID
*
* Course: CPE2600
* Section: 111
* Assignment: Lab 9 (System Calls)
* Date: 11/14/2024 (Last Updated)
* Name: Jadyn Osborne
*****************************************************************/

#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char* argv[])
{
    pid_t pid; // creating variable to hold current process ID
    if (argc == 2) { // user entered 
        pid = atoi(argv[1]); // stores integer value of string passed
    } else {
        pid = getpid(); // did not use command line
    }

    // Getting the process priority
    int priority = getpriority(PRIO_PROCESS,pid);
    if (priority == -1) {
        perror("Error. Failed to get proceesing priority.");
        exit(1);
    }
    printf("Process priority: %d\n", priority);

    // Getting and Printing the scheduler policy
    int sched_policy = sched_getscheduler(pid);
    if (sched_policy == -1) {
        perror ("Error. Failed to get scheduler policy.");
        exit(1);
    }

    // Printing the scheduler policy as a string
    // Policy can be unknown, first in first out, round robin, or other
    switch (sched_policy) {
        case SCHED_FIFO: printf("Scheduler: SCHED_FIFO\n");
            break;
        case SCHED_OTHER: printf("Scheduler: SCHED_OTHER\n");
            break;
        case SCHED_RR: printf("Scheduler: SCHED_RR\n");
            break;
        default: printf("Scheduler: Type unknown\n");
    }

    return 0;
}