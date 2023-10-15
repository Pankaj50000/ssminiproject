#ifndef FACULTY_H
#define FACULTY_H
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include"authenticate.h"
#include"add.h"
#include"facultyFunction.h"
int faculty(int fd){
const char *filename = "FacultyRecord.txt";
		char inputUsername[50];
                char readBuffer[1000], writeBuffer[1000];
     ssize_t readBytes, writeBytes;
    	char inputPassword[50];
		//printf("enter Username: ");
                 char prompt2[500]="Enter Username\n";
 writeBytes = write(fd, prompt2, strlen(prompt2));
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
        strcpy(inputUsername,readBuffer);

		//scanf("%s",inputUsername);
		//printf("enter Password: ");
		//scanf("%s",inputPassword);
  char prompt3[500]="Enter Password\n";
 writeBytes = write(fd, prompt3, strlen(prompt3));
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
        strcpy(inputPassword,readBuffer);

		int result = authenticatefaculty(filename, inputUsername, inputPassword);
    	if (result == 1) {
			int c;
        	//printf("Authentication successful. Welcome, %s!\n", inputUsername);
		 char prompt[500]="Authentication successful. Welcome\n";
 writeBytes = write(fd, prompt, strlen(prompt));
          char prompt1[10000]="################ Welcome to Faculty Menu #################\n do you want to:\n 1.Add new Course 2.Remove offered Course 3.View enrollments in Courses 4.Change Password5.Logout and Exit ";
 writeBytes = write(fd, prompt1, strlen(prompt1));
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
	c=atoi(readBuffer);
	switch(c){
                case 1:addcourse(fd);
                    
                       break;
                case 2:removecourse(fd);
                       break;
               // case 3:Activate/Deactivate-student();
                    //   break;
               // case 4:update-student/facultydetails();
                      // break();
                case 5:return 1;
                default:printf("enter a valid choice\n");
		
    	} 
        }else if (result == 0) {
        printf("Authentication failed. Invalid username or password.\n");
    	} else {
        printf("Error occurred during authentication.\n");
    	}

}


#endif
