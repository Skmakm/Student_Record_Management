#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	int rollno;
	char name[30];
	float percentage;
	struct student *next;
}SLL;

void addrecord(SLL **);
void delrecord(SLL **);
void showrecord(SLL *);
void modifyrecord(SLL *);
void saverecord(SLL *);
void loadrecord(SLL **);
void sortrecord(SLL *);
void delallrecord(SLL **);
void revrecord(SLL **);

 
