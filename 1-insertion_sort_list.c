#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to head of list
 */

void insertion_sort_list(listint_t **list)
{
    if (list == NULL  *list == NULL  (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            /* swap nodes */
            listint_t *next = current->next;
            listint_t *prev2 = prev->prev;
            prev->next = next;
            if (next != NULL)
                next->prev = prev;
            prev->prev = current;
            current->next = prev;
            current->prev = prev2;
            if (prev2 != NULL)
                prev2->next = current;
            else
                *list = current;

            /* print list after each swap */
            print_list(*list);
            prev = current->prev;
        }
        current = current->next;
    }
}
