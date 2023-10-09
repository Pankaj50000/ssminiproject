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
void addStudentInfo(){
    char name[100],rollno[100],emailId[100],password[100];
			printf("Name of Student: ");
			scanf("%s",name);
			printf("Roll No of Student: ");
			scanf("%s",rollno);
			printf("Email Id of Student: ");
			scanf("%s",emailId);
			printf("Password of Student: ");
			scanf("%s",password);
			if(addStudent(name,rollno,emailId,password)==1){
				printf("Successfully Added Student!\n");
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
    int fd = open("StudentRecord.txt",O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd==-1){
       perror("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd, &student, sizeof(struct Student));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 0;
    }
    close(fd);
    return 1;
}
void addFacultyInfo(){
    char name[100],emailId[100],password[100];
			printf("Name of Faculty: ");
			scanf("%s",name);
			printf("Email Id of Faculty: ");
			scanf("%s",emailId);
			printf("Password of Faculty: ");
			scanf("%s",password);
			if(addFaculty(name,emailId,password)==1){
				printf("Successfully Added Faculty!\n");
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
    int fd = open("FacultyRecord.txt", O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd==-1){
        perror("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd, &faculty, sizeof(struct Faculty));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 0;
    }
    return 1;
}
#endif
