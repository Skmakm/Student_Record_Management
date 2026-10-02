#include"student.h"

int main()
{
	SLL *head=0;
	char ch;

	loadrecord(&head);

	while(1)
	{
		printf("\n************* STUDENT RECORD NEW ***********\n");
		printf("a/A : Add new record\n");
		printf("d/D : Delete a record\n");
		printf("s/S : Show the list\n");
		printf("m/M : Modify a record\n");
		printf("v/V : Save records\n");
		printf("e/E : Exit\n");
		printf("t/T : Sort the list\n");
		printf("l/L : Delete all the records\n");
		printf("r/R : Reverse the list\n");
		printf("Enter your choice: ");	

		scanf(" %c",&ch);

		switch (ch)
		{
			case 'a':
			case 'A':addrecord(&head);
				 break;

			case 'd':
			case 'D':delrecord(&head);
				 break;

			case 's':
			case 'S':showrecord(head);
				 break;

			case 'm':
			case 'M':modifyrecord(head);
				 break;

			case 'v':
			case 'V':saverecord(head);
				 break;

			case 't':
			case 'T':sortrecord(head);
				 break;

			case 'l':
			case 'L':delallrecord(&head);
				 break;

			case 'r':
			case 'R':revrecord(&head);
				 break;

			case 'e':
			case 'E':
				 {
					 char exit_ch;

					 printf("\nS/s : Save and exit\n");
					 printf("E/e : Exit without saving\n");
					 printf("Enter your choice: ");
					 scanf(" %c", &exit_ch);

					 if (exit_ch == 's' || exit_ch == 'S')
					 {
						 saverecord(head);
						 delallrecord(&head);
						 printf("Program terminated.\n");
						 return 0;
					 }
					 else if (exit_ch == 'e' || exit_ch == 'E')
					 {
						 delallrecord(&head);
						 printf("Program terminated without saving.\n");
						 return 0;
					 }
					 else
					 {
						 printf("Invalid choice.\n");
					 }

					 break;
				 }

			default:printf("Invalid menu choice. Please try again.\n");
		}
	}

	return 0;
}
