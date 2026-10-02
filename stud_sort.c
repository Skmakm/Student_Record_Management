#include "student.h"

void sortrecord(SLL *ptr)
{
    SLL *i;
    SLL *j;

    int roll;
    float percentage;
    char name[30];

    char ch;

    if (ptr == 0)
    {
        printf("No records available.\n");
        return;
    }

    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);

    if (ch == 'n' || ch == 'N')
    {
        for (i = ptr; i != 0; i = i->next)
        {
            for (j = i->next; j != 0; j = j->next)
            {
                if (strcmp(i->name, j->name) > 0)
                {
                    roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = roll;

                    strcpy(name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, name);

                    percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = percentage;
                }
            }
        }

        printf("Sorted by name.\n");
    }

    else if (ch == 'p' || ch == 'P')
    {
        for (i = ptr; i != 0; i = i->next)
        {
            for (j = i->next; j != 0; j = j->next)
            {
                if (i->percentage < j->percentage)
                {
                    roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = roll;

                    strcpy(name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, name);

                    percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = percentage;
                }
            }
        }

        printf("Sorted by percentage.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
