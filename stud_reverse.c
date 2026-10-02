#include "student.h"

void delallrecord(SLL **ptr)
{
    SLL *temp;

    while (*ptr != 0)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;

        free(temp);
    }

    printf("All records deleted.\n");
}

void revrecord(SLL **ptr)
{
    SLL *prev = 0;
    SLL *current = *ptr;
    SLL *next;

    if (*ptr == 0)
    {
        printf("No records available.\n");
        return;
    }

    while (current !=0)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    *ptr = prev;

    printf("List reversed.\n");
}
