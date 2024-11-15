/*****************************************************************
* @file info.c
* @brief Prints various types of system information
*
* Course: CPE2600
* Section: 111
* Assignment: Lab 9 (System Calls)
* Date: 11/14/2024 (Last Updated)
* Name: Jadyn Osborne
*****************************************************************/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Getting and Printing system information using uname
    struct utsname sys_info; // Declaring structure holding system information
    uname(&sys_info); // calling function to fill in sys_info structure
    if (uname(&sys_info) == -1) { // check for potential error return
        perror("Error. Failed to get system information.");
        exit(1);
    }
    if (sys_info.nodename[0] != '\0') {
        printf("Host name: %s\n", sys_info.nodename);
    }
    if (sys_info.sysname[0] != '\0') {
        printf("OS name: %s\n", sys_info.sysname);
    }
    if (sys_info.release[0] != '\0') {
        printf("OS release version: %s\n", sys_info.release);
    }
    if (sys_info.version[0] != '\0') {
        printf("OS version: %s\n", sys_info.version);
    }
    if (sys_info.machine[0] != '\0') {
        printf("Hardware name: %s\n", sys_info.machine);
    }
    
    // Getting and Printing number of CPUs
    long cpus = sysconf(_SC_NPROCESSORS_ONLN);
    if (cpus > 0) {
        printf("Number of CPUs: %ld\n", cpus);
    }
    
    // Getting and Printing memory information
    struct sysinfo mem_info;
    if (sysinfo(&mem_info) == -1) {
        perror("Error. Failed to get memory information");
        exit(1);
    } // if no fail, print results below
    printf("Total free memory: %lu bytes\n", 
    mem_info.freeram * mem_info.mem_unit);
    printf("Total physical memory: %lu bytes\n", 
    mem_info.totalram * mem_info.mem_unit);
    return 0;
}