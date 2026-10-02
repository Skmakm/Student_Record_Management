#include"student.h"

void delrecord(SLL **ptr)
{
	char ch;
	int roll;
	char name[30];

	SLL *temp;
	SLL *prev;

	if(*ptr==0)
	{
		printf("No records available\n");
		return;
	}

	printf("R/r : Delete by roll number\n");
	printf("N/n : Delete by name\n");
	printf("Enter choice: ");
	scanf(" %c", &ch);

	if(ch=='r' || ch=='R')
	{
		printf("Enter the roll number: ");
		scanf("%d",&roll);

		temp=*ptr;
		prev=0;

		while(temp!=0)
		{
			if(temp->rollno==roll)
			{
				if(prev==0)
				{
					*ptr=temp->next;
				}
				else
				{
					prev->next=temp->next;
				}

				free(temp);

				printf("Record Deleted\n");
				return;
			}

			prev=temp;
			temp=temp->next;
		}

		printf("Record not found\n");
	}

	else if(ch=='n' || ch=='N')
	{
		printf("Enter name: ");
		scanf("%s",name);

		temp=*ptr;

		printf("\n Matching Records \n");

		while(temp!=0)
		{
			if(strcmp(temp->name,name)==0)
			{
				printf("Roll no=%d Name=%s Percentage=%.2f\n",temp->rollno,temp->name,temp->percentage);
			}

			temp=temp->next;
		}

		printf("Enter the roll number to delete: ");
		scanf("%d",&roll);

		temp=*ptr;
		prev=0;

		while(temp!=0)
		{
			if(temp->rollno==roll)
			{
				if(prev==0)
				{
					*ptr=temp->next;
				}
				else
				{
					prev->next=temp->next;
				}

				free(temp);

				printf("Record deleted \n");
				return;
			}

			prev=temp;
			temp=temp->next;
		}

		printf("Record not found\n");
	}
	else
	{
		printf("Invalid choice\n");
	}
}

