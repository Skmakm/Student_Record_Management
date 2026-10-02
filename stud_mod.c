#include"student.h"

void modifyrecord(SLL *ptr)
{
	char ch;
	int roll;
	char name[30];
	float percentage;

	SLL *temp=ptr;

	if(ptr==0)
	{
		printf("No records available\n");
		return;
	}

	printf("R/r : Search by roll number\n");
	printf("N/n : Search by name\n");
	printf("P/p : Search by percentage\n");
	printf("Enter choice: ");
	scanf(" %c", &ch);

	if (ch == 'r' || ch == 'R')
	{
		printf("Enter roll number: ");
		scanf("%d", &roll);

		while (temp != 0)
		{
			if (temp->rollno == roll)
				break;

			temp = temp->next;
		}
	}

	else if (ch == 'n' || ch == 'N')
	{
		printf("Enter name: ");
		scanf("%s", name);

		while (temp != 0)
		{
			if (strcmp(temp->name, name) == 0)
			{
				printf("Roll No: %d Name: %s Percentage: %.2f \n",temp->rollno,temp->name,temp->percentage);
			}

			temp = temp->next;
		}

		printf("Enter roll number to modify: ");
		scanf("%d", &roll);


		temp = ptr;

		while (temp !=0)
		{
			if (temp->rollno == roll)
				break;

			temp = temp->next;
		}
	}

	else if (ch == 'p' || ch == 'P')
	{
		printf("Enter percentage: ");
		scanf("%f", &percentage);

		while (temp !=0)
		{
			if (temp->percentage == percentage)
			{
				printf("Roll No: %d Name: %s Percentage: %.2f\n",temp->rollno,temp->name,temp->percentage);
			}

			temp = temp->next;
		}

		printf("Enter roll number to modify: ");
		scanf("%d", &roll);

		temp = ptr;

		while (temp != 0)
		{
			if (temp->rollno == roll)
				break;

			temp = temp->next;
		}
	}


	else
	{
		printf("Invalid choice.\n");
		return;
	}

	if (temp == 0)
	{
		printf("Record not found.\n");
		return;
	}

	printf("\nEnter new name: ");
	scanf("%s", temp->name);

	printf("Enter new percentage: ");
	scanf("%f", &temp->percentage);

	if (temp->percentage < 0 ||
			temp->percentage > 100)
	{
		printf("Invalid percentage.\n");
		return;
	}

	printf("Record modified successfully.\n");
}
