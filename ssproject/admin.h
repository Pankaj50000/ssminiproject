#ifndef ADMIN_H
#define ADMIN_H
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include"authenticate.h"
#include"add.h"

int admin(int fd){
       
char uname[50];
char pass[50];
char readBuffer[1000], writeBuffer[1000];
ssize_t readBytes, writeBytes;
 char prompt[500]="enter your Username \n";
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
 strcpy(uname, readBuffer);
 char prompt1[500]="enter your Password \n";
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
 strcpy(pass, readBuffer);
int result= authenticate_user(uname, pass);
if (result) {
        int b;
        char prompt2[500]=" ################# Welcome to ADMIN Menu ################# \n do you want to: \n 1. add student  2. add faculty 3. activate/deactivate student 4. update student/faculty details 5. exit \n";
        writeBytes = write(fd, prompt2, strlen(prompt2));
       // printf("################# Welcome to ADMIN Menu #################\n");
        //printf("do you want to:\n");
        //printf("1.add student  2.add faculty 3.activate/deactivate student 4.update student/faculty details 5.exit\n");
        bzero(readBuffer, sizeof(readBuffer));
       readBytes = read(fd, readBuffer, sizeof(readBuffer));
       if (readBytes == -1)
              perror("Error while reading from client");
       else if (readBytes == 0)
             printf("No data was sent by the client");
        b=atoi(readBuffer);
        switch(b){
                case 1:addStudentInfo(fd);
                       break;
                case 2:addFacultyInfo(fd);
                       break;
               // case 3:Activate/Deactivate-student();
                    //   break;
               // case 4:update-student/facultydetails();
                      // break();
                case 5:return 1;
                default:printf("enter a valid choice\n");
}
       //return 1;
    } else {
        printf( "Invalid username or password. Login failed.");
        //return 0;
    }


return result;

}


#endif
