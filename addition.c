/*
 * Function: add
 * ----------------------------
 * Adds two large numbers represented as doubly linked lists.
 * Each node stores 4 digits (base 10000).
 *
 * head1, tail1 → first number
 * head2, tail2 → second number
 * res_h, res_t → result linked list (output)
 */

#include "header.h"

/* Adds two large numbers */
void add(cal *head1, cal *tail1, cal *head2, cal *tail2,
         cal **res_h, cal **res_t)
{
    int carry = 0;   // Stores carry generated during addition

    /*
     * Traverse both linked lists from right to left (LSB → MSB)
     * Continue until both lists are exhausted and no carry remains
     */
    while (tail1 || tail2 || carry)
    {
        int sum = carry;   // Start with previous carry

        /*
         * Add current digit from first number (if exists)
         */
        if (tail1)
        {
            sum += tail1->data;     // Add node value
            tail1 = tail1->prev;    // Move to previous node
        }

        /*
         * Add current digit from second number (if exists)
         */
        if (tail2)
        {
            sum += tail2->data;     // Add node value
            tail2 = tail2->prev;    // Move to previous node
        }

        /*
         * Since base = 10000:
         * - carry is quotient
         * - current digit is remainder
         */
        carry = sum / 10000;   // Calculate carry for next step
        sum %= 10000;          // Store only 4 digits in current node

        /*
         * Insert result at beginning because we are
         * processing from least significant digit
         */
        insert_at_beginning(res_h, res_t, sum);
    }
}