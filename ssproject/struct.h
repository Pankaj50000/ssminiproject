#ifndef STRUCT_H
#define STRUCT_H

struct Course{
	char course_name[100];
};
struct Student{
	char name[100];
	char rollno[100];
	char emailId[100];
	char password[100];
	int status;
	struct Course course_enrolled[10];
};
struct Faculty{
	char name[100];
	char emailId[100];
	char password[100];
	struct Course course_offered[10];
};

#endif
