#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

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
