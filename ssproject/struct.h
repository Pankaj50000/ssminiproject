#ifndef STRUCT_H
#define STRUCT_H

struct Course{
	char course_name[50];
	char course_code[50];
    int available_seats;


};
struct Student{
	char name[50];
	char rollno[50];
	char emailId[50];
	char password[50];
	int status;
	struct Course course_enrolled[10];
};
struct Faculty{
	char name[50];
	char emailId[50];
	char password[50];
	struct Course course_offered[10];
};

#endif
