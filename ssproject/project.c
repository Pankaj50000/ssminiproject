#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include"admin.h"
#include"authenticate.h"
void main(){
int c;
printf("......................Welcome Back To Academia::course Registration.................... \n");
printf("enter your choice {1.Admin 2.Student 3.Faculty} \n");
scanf("%d",&c);
switch(c){
       case 1:admin();
	      break;
       //case 2:student();
           //   break;
       //case 3:faculty();
         //     break;
        default:printf("Enter a valid login type");
         }

    
       }
