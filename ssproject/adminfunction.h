#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"struct.h"
 
int Activate/Deactivate-student(){
             char rollno[50];
           char readBuffer[1000], writeBuffer[1000];
            ssize_t readBytes, writeBytes;
          char prompt[500]="Enter a Roll no. of student to activate/dactivate \n";
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
 strcpy(rollno, readBuffer);
 }
