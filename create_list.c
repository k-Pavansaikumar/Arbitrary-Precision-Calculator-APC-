/*
 * Function: insert_at_beginning
 * --------------------------------
 * Inserts a new node at the beginning of the doubly linked list.
 * Updates both head and tail if the list is initially empty.
 */

#include "header.h"
void insert_at_beginning(cal **head, cal **tail, int value)
{
    cal *new = malloc(sizeof(cal));   // Allocate memory for new node

    // Check for memory allocation failure
    if (!new)
    {
        printf("Memory error\n");
        return;
    }

    // Initialize new node
    new->data = value;
    new->prev = NULL;
    new->next = NULL;

    // If list is empty, new node becomes both head and tail
    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        // Insert at beginning
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

/* Insert node at end (used for correct copying in division) */
void insert_at_end(cal **head, cal **tail, int value)
{
    cal *new = malloc(sizeof(cal));

    if (!new)
    {
        printf("Memory error\n");
        return;
    }

    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
}
/*
 * Function: create_linked_list_from_string
 * ------------------------------------------
 * Converts a string number into a linked list.
 * Each node stores 4 digits (base 10000).
 * Also detects if the number is negative.
 */
void create_linked_list_from_string(cal **head, cal **tail,
                                    const char *number,
                                    int *is_negative)
{
    // Check sign of number
    if (number[0] == '-')
    {
        *is_negative = 1;
        number++;   // Skip '-' sign
    }
    else
    {
        *is_negative = 0;

        if (number[0] == '+')
        {
            number++;   // Skip '+' sign
        }
    }

    int len = strlen(number);   // Length of number string

    /*
     * Break number into chunks of 4 digits (from right to left)
     * Example: 12345678 → [1234][5678]
     */
    while (len > 0)
    {
        int size = (len >= 4) ? 4 : len;
        char temp[5];   // Temporary buffer for 4 digits + '\0'

        // Copy last 'size' digits
        strncpy(temp, number + len - size, size);
        temp[size] = '\0';

        // Convert to integer and insert into list
        insert_at_beginning(head, tail, atoi(temp));

        len -= size;
    }
}

/*
 * Function: free_linked_list
 * -----------------------------
 * Frees all nodes of the linked list to avoid memory leaks.
 */
void free_linked_list(cal *head)
{
    while (head)
    {
        cal *temp = head;
        head = head->next;
        free(temp);
    }
}

/*
 * Function: compare_linked_lists
 * --------------------------------
 * Compares two large numbers represented as linked lists.
 *
 * Returns:
 *  1  → first number is greater
 * -1  → second number is greater
 *  0  → both are equal
 */
int compare_linked_lists(cal *h1, cal *h2)
{
    int c1 = 0, c2 = 0;

    // Count number of nodes in both lists
    for (cal *t = h1; t; t = t->next)
    {
        c1++;
    }

    for (cal *t = h2; t; t = t->next)
    {
        c2++;
    }

    // Compare lengths first
    if (c1 > c2)
    {
        return 1;
    }
    if (c1 < c2)
    {
        return -1;
    }

    // If lengths are equal, compare node by node
    while (h1 && h2)
    {
        if (h1->data > h2->data)
        {
            return 1;
        }
        if (h1->data < h2->data)
        {
            return -1;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    return 0;   // Numbers are equal
}

/*
 * Function: print_list
 * ----------------------
 * Prints the number stored in linked list format.
 * Maintains proper formatting with leading zeros.
 */
void print_list(cal *head, int is_negative)
{
    // If list is empty → print 0
    if (!head)
    {
        printf("0\n");
        return;
    }

    // Print negative sign if needed
    if (is_negative)
    {
        printf("-");
    }

    // Print first node normally
    printf("%d", head->data);
    head = head->next;

    // Print remaining nodes with leading zeros (4 digits)
    while (head)
    {
        printf("%04d", head->data);
        head = head->next;
    }

    printf("\n");
}

/*
 * Function: remove_leading_zeros
 * --------------------------------
 * Removes unnecessary leading zeros from the result list.
 * Ensures at least one node remains.
 */
void remove_leading_zeros(cal **head)
{
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        cal *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}