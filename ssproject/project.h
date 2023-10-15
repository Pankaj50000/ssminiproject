#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include"admin.h"
#include"authenticate.h"
#include"student.h"
#include"faculty.h"


void start(int fd){
int c;
char readBuffer[1000], writeBuffer[1000];
ssize_t readBytes, writeBytes;
int userChoice;
char prompt[500] = "......................Welcome Back To Academia::course Registration.................... \nenter your choice {1.Admin 2.Student 3.Faculty} \n";
writeBytes = write(fd, prompt, strlen(prompt));
bzero(readBuffer, sizeof(readBuffer));
readBytes = read(fd, readBuffer, sizeof(readBuffer));
if (readBytes == -1)
    perror("Error while reading from client");
else if (readBytes == 0)
    printf("No data was sent by the client");
c = atoi(readBuffer);
switch(c){
       case 1:admin(fd);
	      break;
       case 2:student(fd);
        break;
       case 3:faculty(fd);
        break;
        default:printf("Enter a valid login type");
         }

    
       }
