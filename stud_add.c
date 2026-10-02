#include "student.h"

void addrecord(SLL **ptr)
{
	SLL *new;
	SLL *temp;
	int roll=1;
	int flag;

	new=malloc(sizeof(SLL));

	if(new==0)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	while(1)
	{
		flag=0;
		temp=*ptr;

		while(temp!=0)
		{
			if(temp->rollno==roll)
			{
				flag=1;
				break;
			}

			temp=temp->next;

		}

		if(flag==0)
			break;

		roll++;
	}

	new->rollno=roll;

	printf("Enter name:\n");
	scanf(" %[^\n]",new->name);
	printf("Enter percentage:\n");
	scanf("%f",&new->percentage);

	if(new->percentage < 0 || new->percentage >100)
	{
		printf("Invalid Percentage \n");
		free(new);
		return;
	}

	new->next=0;

	if(*ptr==0)
		*ptr=new;
	else
	{
		temp=*ptr;

		while(temp->next!=0)
			temp=temp->next;

		temp->next=new;
	}

	printf("Record Added Successfully \n");
}
