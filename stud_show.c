#include"student.h"

void showrecord(SLL *ptr)
{
	SLL *temp=ptr;

	if(ptr==0)
	{
		printf("No student records available\n");
		return;
	}

	printf("\n-----------------------\n");
	printf("Roll no.\tName\t\tPercentage\n");
	printf("------------------------\n");

	while(temp!=0)
	{
		printf("%d\t\t%s\t\t%.2f\n",temp->rollno,temp->name,temp->percentage);

		temp=temp->next;
	}

	printf("---------------------------\n");
}

