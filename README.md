# Lab 9: system-calls - CPE 2600 Fall 2024

## Brief
Assignment focuses on becoming familiar with different **POSIX system calls**

### Information Maintenance
- `info.c` prints the following
 - Current time of day (in nanoseconds)  
 - System's network name  
 - Operating system name  
 - Operating system release and version  
 - System's hardware type  
 - Number of CPUs  
 - Total physical memory (in bytes)  
 - Free memory (in bytes)

### Process Control
 - `pinfo.c` displays given process details (current process by default)
 - Process priority  
 - Scheduling method (in human-readable format)  
 - Error handling for non-existent processes 
 
 - `pmod.c` will modify a process's priority and make it sleep for a specified time  
 - Reduce the process priority by 10  
 - Sleep for a specified number of nanoseconds  
 - Prints a goodbye message and exit

 ### File Management
 - `finfo.c` will retrieve and display file information 
  - File type (user-readable)  
  - File permissions (user-readable)  
  - File owner (user identifier)  
  - File size (in bytes)  
  - Last modification date and time (formatted for easy viewing)