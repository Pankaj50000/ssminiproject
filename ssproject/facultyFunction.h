#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"struct.h"



int add_new_course(char* course_code, char* course_name, int available_seats);
int remove_course( char* course_code_to_remove);
//
int addcourse(int fd){
char readBuffer[1000], writeBuffer[1000];
char coursename[50],coursecode[50];
int seat;
ssize_t readBytes, writeBytes;
 char prompt[500]="enter course code to add :";
 writeBytes = write(fd, prompt, strlen(prompt));
 if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");
    else
    {
bzero(readBuffer, sizeof(readBuffer));
readBytes = read(fd, readBuffer, sizeof(readBuffer));
if (readBytes == -1)
    perror("Error while reading from client");
else if (readBytes == 0)
    printf("No data was sent by the client");
    }
 strcpy(coursecode, readBuffer);
 char prompt1[500]="enter course name to add: \n";
 writeBytes = write(fd, prompt1, strlen(prompt));
 if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");
    else
    {
bzero(readBuffer, sizeof(readBuffer));
readBytes = read(fd, readBuffer, sizeof(readBuffer));
if (readBytes == -1)
    perror("Error while reading from client");
else if (readBytes == 0)
    printf("No data was sent by the client");
    }
 strcpy(coursename, readBuffer);
 char prompt3[500]="enter availabe seat for that course \n";
 writeBytes = write(fd, prompt3, strlen(prompt));
 if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");
    else
    {
bzero(readBuffer, sizeof(readBuffer));
readBytes = read(fd, readBuffer, sizeof(readBuffer));
if (readBytes == -1)
    perror("Error while reading from client");
else if (readBytes == 0)
    printf("No data was sent by the client");
    }
 seat=atoi(readBuffer);
 //add_new_course(coursecode,coursename,seat);
 if(add_new_course(coursecode,coursename,seat)==1){
				char prompt4[500]="Course Added succesfully!:";
 writeBytes = write(fd, prompt4, strlen(prompt4));
			}
			else{
				printf("Error\n");
			}
}
int add_new_course(char* course_code, char* course_name, int available_seats) {
    int num_courses = 0;
    struct Course courses;
    if (num_courses < 10) {
        strcpy(courses.course_code, course_code);
        strcpy(courses.course_name, course_name);
        courses.available_seats = available_seats;
        num_courses++;
    }
        int fd1 = open("CourseRecord.txt",O_WRONLY | O_CREAT | O_APPEND, 0641);
    if(fd1==-1){
       perror("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd1, &courses, sizeof(struct Course));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd1);
       return 0;
    }
    close(fd1);
    return 1;
    }
 
//

 int removecourse(int fd){
               char removecourse[50];
              char readBuffer[1000], writeBuffer[1000];
              ssize_t readBytes, writeBytes;
             char prompt[500]="enter course code to remove :";
              writeBytes = write(fd, prompt, strlen(prompt));
 if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");
    else
    {
bzero(readBuffer, sizeof(readBuffer));
readBytes = read(fd, readBuffer, sizeof(readBuffer));
if (readBytes == -1)
    perror("Error while reading from client");
else if (readBytes == 0)
    printf("No data was sent by the client");
    }
 strcpy(removecourse,readBuffer);
 if(remove_course(removecourse)==1){
                 char prompt1[500]="Course Removed succesfully!:";
 writeBytes = write(fd, prompt1, strlen(prompt1));
                        }
                        else{
                                printf("Error\n");



                              }

                                    }
int remove_course( char* course_code_to_remove) {
                     int file_descriptor = open("CourseRecord.txt", O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        return 0;
    }

    // Create a temporary file to store courses excluding the one to be removed
    int temp_file_descriptor = open("temp_courserecord.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (temp_file_descriptor == -1) {
        perror("Error creating temporary file");
        close(file_descriptor);
        return 0;
    }

    struct Course current_course;
    ssize_t bytes_read;
    while ((bytes_read = read(file_descriptor, &current_course, sizeof(struct Course))) > 0) {
        // Compare the course code, skip the course to be removed
        if (strcmp(current_course.course_code, course_code_to_remove) != 0) {
            ssize_t bytes_written = write(temp_file_descriptor, &current_course, bytes_read);
            if (bytes_written != bytes_read) {
                perror("Error writing to temporary file");
                close(file_descriptor);
                close(temp_file_descriptor);
                return 0;
            }
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
    }

    close(file_descriptor);
    close(temp_file_descriptor);
     remove("CourseRecord.txt");

    // Replace the original file with the temporary file
    if (rename("temp_courserecord.txt", "CourseRecord.txt") == -1) {
        perror("Error renaming temporary file");
                                                               }
return 1;

}
