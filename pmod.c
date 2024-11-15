/*****************************************************************
* @file pmod.c
* @brief reduces priority of process by 10, has the process sleep
* for 1,837,272,638 nanoseconds, prints goodbye, and exits
*
* Course: CPE2600
* Section: 111
* Assignment: Lab 9 (System Calls)
* Date: 11/14/2024 (Last Updated)
* Name: Jadyn Osborne
*****************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    // Reducing own process priority by 10
    // nice is a concept used by Linux to influence process priority
    int result = nice(10);
    if (result == -1) {
        perror("Error. Failed to set process priority");
        exit(1);
    }
    printf("Process priority was reduced by 10.\n");

    // Having the process sleep for 1,837,272,638 nanoseconds
    struct timespec req = {1, 837272638}; // 1 second and 837,272,638 ns
    nanosleep(&req, NULL); // req values used to sleep process for given time
    
    // Saying goodbye by printing to console
    printf("Goodbye!\n");
    return 0;
}