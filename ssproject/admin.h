#ifndef ADMIN_H
#define ADMIN_H
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include"authenticate.h"
#include"add.h"
int admin(){
char uname[50];
char pass[50];
 printf("enter your Username \n");
 scanf(" %s", uname);
printf("enter your password \n");
scanf("%s",pass);
int result= authenticate_user(uname, pass);
if (result) {
        int b;
        printf("Login successful. Welcome to Academia Portal!");
        printf("do you want to:\n");
        printf("1.add student  2.add faculty 3.activate/deactivate student 4.update student/faculty details 5.exit\n");
        scanf("%d",&b);
        switch(b){
                case 1:addStudentInfo();
                       break;
                case 2:addFacultyInfo();
                       break;
                //case 3:
                //case 4:
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
