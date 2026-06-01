#include "header.h"
/*
 * Function: subtraction
 * -------------------------
 * Performs subtraction of two large numbers represented as doubly linked lists.
 * Each node contains a chunk of the number (base 10000).
 *
 * head1, tail1 → First number
 * head2, tail2 → Second number
 * res_h, res_t → Result list (output)
 */
#include "header.h"

void sub(cal *head1, cal *tail1, cal *head2, cal *tail2,
         cal **res_h, cal **res_t)
{
    int borrow = 0;   // Stores borrow during subtraction

    /*
     * Traverse both lists from least significant digit (tail)
     * towards most significant digit (head)
     */
    while (tail1 || tail2)
    {
        /*
         * Get current values from nodes
         * If node is NULL, treat value as 09
         */
        int val1 = tail1 ? tail1->data : 0;
        int val2 = tail2 ? tail2->data : 0;

        /*
         * Perform subtraction including previous borrow
         */
        int diff = val1 - val2 - borrow;

        /*
         * If result is negative:
         * → borrow from next higher digit
         * → adjust using base (10000)
         */
        if (diff < 0)
        {
            diff += 10000;   // Adjust value using base
            borrow = 1;      // Set borrow for next iteration
        }
        else
        {
            borrow = 0;      // No borrow needed
        }

        /*
         * Insert the result at the beginning
         * (since we process from LSB → MSB)
         */
        insert_at_beginning(res_h, res_t, diff);

        /*
         * Move to next higher digit
         */
        if (tail1) tail1 = tail1->prev;
        if (tail2) tail2 = tail2->prev;
    }
}