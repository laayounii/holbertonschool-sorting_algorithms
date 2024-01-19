#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Pointer to the pointer of the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;
        prev = current->prev;

        while (prev && temp->n < prev->n)
        {
            if (temp->next)
                temp->next->prev = prev;

            prev->next = temp->next;
            temp->next = prev;
            temp->prev = prev->prev;

            if (prev->prev)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;

            print_list(*list);
            prev = temp->prev;
        }

        current = current->next;
    }
}
