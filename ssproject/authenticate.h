#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"

int authenticatefaculty(const char *filename, const char *inputUsername, const char *inputPassword) {
    struct Faculty user;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
    }
	//printf("%d\n",fd);
    while (read(fd, &user, sizeof(user)) > 0) {
      //  printf("%s %s", user.emailId, user.password);
        if (strcmp(inputUsername, user.emailId) == 0 && strcmp(inputPassword, user.password) == 0 ) {
            close(fd);
            return 1;  
        }
    }

    close(fd);
    return 0;  
}
int authenticatestudent(const char *filename, const char *inputUsername, const char *inputPassword) {
    struct Student user;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
    }
	printf("%d\n",fd);
    while (read(fd, &user, sizeof(user)) > 0) {
        printf("%s %s", user.emailId, user.password);
        if (strcmp(inputUsername, user.emailId) == 0 && strcmp(inputPassword, user.password) == 0 ) {
            close(fd);
            return 1;  
        }
    }

    close(fd);
    return 0;  
}

int authenticate_user(char* username, char* password){
struct admin {

    char username[50];

    char password[50];

};



struct admin Admin[3] = {

    {"admin1", "password1"},

    {"admin2", "password2"},

    // Add more users as needed

};

    for (int i = 0; i < 2; ++i) {

        if (strcmp(Admin[i].username, username) == 0 && strcmp(Admin[i].password, password) == 0) {

            return 1;  // Authentication successful

        }else{

    return 0;

            }
      
              }
}

#endif
