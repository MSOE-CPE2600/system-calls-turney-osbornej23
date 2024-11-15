/*****************************************************************
* @file finfo.c
* @brief retrieves and prints file information

* Course: CPE2600
* Section: 111
* Assignment: Lab 9 (System Calls)
* Date: 11/14/2024 (Last Updated)
* Name: Jadyn Osborne
*****************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

/**
 * @brief Displays permissions of a file by checking for 
 * various permission bits. Uses bitwise AND operations to do so.
 */
void print_permissions(mode_t mode) {
    printf("Permissions: ");
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}
int main(int argc, char* argv[])
{
    if (argc != 2) { // check for correct number of args
        printf("Invalid or empty command line input");
        exit(1);
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error. Failed to retrieve file information.");
        exit(1);
    }

    // Getting and Printing the type of file
    // below uses function calls to check file_stat
    // content to determine what type of file it is, then prints
    printf("File type: "); 
    if (S_ISREG(file_stat.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("Directory\n");
    } else {
        printf("Other\n");
    }

    // Printing the permissions for given file
    print_permissions(file_stat.st_mode);

    // Printing the owner of the file
    printf("Owner: %u\n", file_stat.st_uid);

    // Printing the file size
    printf("File size: %ld bytes\n", file_stat.st_size);

    // Printing time of last modification to file
    char timebuffer[80]; // array of character to hold string
    // timeinfo is a pointer to struct tm that holds the time of modification
    struct tm *timeinfo = localtime(&file_stat.st_mtime);
    // Converts timeinfo struct into a string stored in timebuffer
    strftime(timebuffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    // Prints the last modification date information in timebuffer string
    printf("Last modified: %s\n", timebuffer);
    return 0;
}