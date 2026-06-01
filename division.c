/*
 * Function: divide
 * ------------------------
 * Performs division of two large numbers using linked lists.
 * Uses repeated subtraction method.
 *
 * head1 → dividend
 * head2 → divisor
 * res_h → quotient (result)
 *
 * NOTE: This is a simple implementation (not optimized).
 */

 #include "header.h"

void divide(cal *head1, cal *tail1, cal *head2, cal *tail2,
            cal **res_h, cal **res_t)
{
    cal *temp_h = NULL, *temp_t = NULL;

    /* Division by zero check */
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero\n");
        return;
    }

    /*
     * Step 1: Copy dividend into temp list
     */
    for (cal *p = head1; p; p = p->next)
    {
        insert_at_end(&temp_h, &temp_t, p->data);
    }

    /*
     * Step 2: Initialize quotient = 0
     */
    insert_at_beginning(res_h, res_t, 0);

    /*
     * Step 3: Repeat subtraction
     */
    while (compare_linked_lists(temp_h, head2) >= 0)
    {
        cal *new_h = NULL;
        cal *new_t = NULL;

        /* Perform subtraction */
        sub(temp_h, temp_t, head2, tail2, &new_h, &new_t);

        /* Free old temp */
        free_linked_list(temp_h);

        /* Update temp */
        temp_h = new_h;
        temp_t = new_t;

    
        remove_leading_zeros(&temp_h);

        /*
         * Add 1 to quotient
         */
        cal *one_h = NULL;
        cal *one_t = NULL;
        insert_at_beginning(&one_h, &one_t, 1);

        cal *tmp_h = NULL;
        cal *tmp_t = NULL;

        add(*res_h, *res_t, one_h, one_t, &tmp_h, &tmp_t);

        /* Update result */
        free_linked_list(*res_h);
        *res_h = tmp_h;
        *res_t = tmp_t;

        /* Free temporary one list */
        free_linked_list(one_h);
    }

    /*
     * Free remaining temp list
     */
    free_linked_list(temp_h);
}