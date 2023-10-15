#ifndef STUDENT_H
#define STUDENT_H
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include"authenticate.h"
#include"add.h"
int student(int fd){
const char *filename = "StudentRecord.txt";
		char inputUsername[50];
    	char inputPassword[50];
		//printf("enter Username: ");
		//scanf("%s",inputUsername);
		 char readBuffer[1000], writeBuffer[1000];
     ssize_t readBytes, writeBytes;
 char prompt[500]="Enter Your username:";
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
 strcpy(inputUsername, readBuffer); 
		//printf("enter Password: ");
		//scanf("%s",inputPassword);
		char prompt1[500]="Enter Your Password:";
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
 strcpy(inputPassword, readBuffer); 

		
		int result = authenticatestudent(filename, inputUsername, inputPassword);
    	if (result == 1) {
			int c;
        	//printf("Authentication successful. Welcome, %s!\n", inputUsername);
 char prompt2[500]="Authentication successful. Welcome..";
 writeBytes = write(fd, prompt, strlen(prompt));
 if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");

			printf("################# Welcome to Student Menu #################\n");
			printf("do you want to:\n");
	        printf("1.View All Courses\n");
	        printf("2.Enroll  new Course\n");
	        printf("3. Unenroll from already enrolled Courses\n");
	        printf("4.Change Password\n");
	        printf("5.Logout and Exit\n");
	        printf("Enter Your Choice:\n");
			//scanf("%d",&c);
    	} else if (result == 0) {
        printf("Authentication failed. Invalid username or password.\n");
    	} else {
        printf("Error occurred during authentication.\n");
    	}

}


#endif
