#ifndef ADD_H
#define ADD_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
int addStudent(const char *name,const char *rollno,const char *emailId,const char *password);
int addFaculty(const char *name,const char *emailId,const char *password);
void addStudentInfo(int fd){
    char name[50],rollno[50],emailId[50],password[50];
             
			//printf("Name of Student: ");
			//scanf("%s",name);
			//printf("Roll No of Student: ");
			//scanf("%s",rollno);
			//printf("Email Id of Student: ");
		char readBuffer[1000], writeBuffer[1000];
     ssize_t readBytes, writeBytes;
 char prompt[500]="Enter Name of Student:";
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
 strcpy(name, readBuffer);	
         char prompt1[500]="Enter Roll no. of Student:";
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
 strcpy(rollno, readBuffer);
 	char prompt2[500]="Enter Email id of Student:";
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
 strcpy(emailId, readBuffer);
      	
char prompt3[500]="Enter Password of Student:";
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
 strcpy(password, readBuffer);

 
 
			//printf("Password of Student: ");
			//scanf("%s",password);
			if(addStudent(name,rollno,emailId,password)==1){
				char prompt4[500]="Student Added succesfully!:";
 writeBytes = write(fd, prompt4, strlen(prompt4));
			}
			else{
				printf("Error\n");
			}
}
int addStudent(const char *name,const char *rollno,const char *emailId,const char *password){
    struct Student student;
    strcpy(student.name,name);
    strcpy(student.rollno,rollno);
    strcpy(student.password,password);
    strcpy(student.emailId,emailId);
    student.status=1;
    int fd1 = open("StudentRecord.txt",O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd1==-1){
       perror("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd1, &student, sizeof(struct Student));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd1);
        return 0;
    }
    close(fd1);
    return 1;
}
void addFacultyInfo(int fd){
    char name[50],emailId[50],password[50];
			//printf("Name of Faculty: ");
			//scanf("%s",name);char prompt[500]="Enter Name of Student:";
            char readBuffer[1000], writeBuffer[1000];
     ssize_t readBytes, writeBytes;
 char prompt[500]="Enter Name of Faculty:";
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
 strcpy(name, readBuffer);
       char prompt1[500]="Enter Email id of Faculty::";
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
 strcpy(emailId, readBuffer);
			//printf("Email Id of Faculty: ");
			//scanf("%s",emailId);
        char prompt2[500]="Enter Password of faculty:";
 writeBytes = write(fd, prompt2, strlen(prompt));
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
 strcpy(password, readBuffer);

			//printf("Password of Faculty: ");
			//scanf("%s",password);
			if(addFaculty(name,emailId,password)==1){
				char prompt4[500]="Faculty Added succesfully!:";
 writeBytes = write(fd, prompt4, strlen(prompt));
			}
			else{
				perror("Error\n");
			}
}
int addFaculty(const char *name,const char *emailId,const char *password){
    struct Faculty faculty;
    strcpy(faculty.name,name);
    strcpy(faculty.password,password);
    strcpy(faculty.emailId,emailId);
    int fd1 = open("FacultyRecord.txt", O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd1==-1){
        perror("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd1, &faculty, sizeof(struct Faculty));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd1);
        return 0;
    }
    return 1;
}
#endif
