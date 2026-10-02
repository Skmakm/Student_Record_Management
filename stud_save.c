#include"student.h"

void saverecord(SLL *ptr)
{
	FILE *fp;
	SLL *temp = ptr;

	fp = fopen("student.dat", "w");

	if (fp == 0)
	{
		printf("File cannot be opened.\n");
		return;
	}

	while (temp != 0)
	{
		fprintf(fp, "%d %s %.2f\n",temp->rollno,temp->name,temp->percentage);

		temp = temp->next;
	}

	fclose(fp);

	printf("Records saved successfully.\n");
}

void loadrecord(SLL **ptr)
{
	FILE *fp;
	SLL *new;
	SLL *temp;

	int roll;
	char name[30];
	float percentage;

	fp = fopen("student.dat", "r");

	if (fp == 0)
	{
		return;
	}

	while (fscanf(fp, "%d %s %f",&roll,name,&percentage) == 3)
	{
		new= malloc(sizeof(SLL));

		if (new == 0)
		{
			fclose(fp);
			return;
		}

		new->rollno = roll;
		new->percentage = percentage;

		int i = 0;

		while (name[i] != '\0')
		{
			new->name[i] = name[i];
			i++;
		}

		new->name[i] = '\0';

		new->next = NULL;

		if (*ptr == 0)
		{
			*ptr = new;
		}
		else
		{
			temp = *ptr;

			while (temp->next != 0)
			{
				temp = temp->next;
			}

			temp->next = new;
		}
	}

	fclose(fp);
}
