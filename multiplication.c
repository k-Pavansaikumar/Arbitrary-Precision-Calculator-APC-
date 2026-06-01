
/*
 * Function: multiply
 * -------------------------
 * Multiplies two large numbers represented as doubly linked lists.
 * Each node stores 4 digits (base 10000).
 *
 * Uses school multiplication method:
 * - Multiply each digit of second number with first number
 * - Shift results accordingly
 * - Add all intermediate results
 */
#include "header.h"

/* Multiply two large numbers */
void multiply(cal *head1, cal *tail1, cal *head2, cal *tail2,
              cal **res_h, cal **res_t)
{
    cal *ptr2 = tail2;   // Pointer for second number (multiplier)
    int shift = 0;       // Tracks position (like multiplying by base^n)

    /*
     * Traverse multiplier from least significant digit (right to left)
     */
    while (ptr2)
    {
        cal *ptr1 = tail1;        // Pointer for first number (multiplicand)
        cal *temp_h = NULL;       // Temporary result head
        cal *temp_t = NULL;       // Temporary result tail
        int carry = 0;            // Carry for multiplication

        /*
         * Add zeros at beginning to simulate shifting
         * (like multiplying by 10, 100, etc.)
         * Here base = 10000
         */
        for (int i = 0; i < shift; i++)
            insert_at_beginning(&temp_h, &temp_t, 0);

        /*
         * Multiply each digit of first number with current digit of second number
         */
        while (ptr1)
        {
            long long prod =
                (long long)ptr1->data * ptr2->data + carry;

            /*
             * Extract carry and current block value
             */
            carry = prod / 10000;       // Carry for next multiplication
            insert_at_beginning(&temp_h, &temp_t, prod % 10000);

            ptr1 = ptr1->prev;   // Move to next higher digit
        }

        /*
         * If carry remains after finishing multiplication, insert it
         */
        if (carry)
            insert_at_beginning(&temp_h, &temp_t, carry);

        /*
         * Add this intermediate result to final result
         */
        cal *new_h = NULL, *new_t = NULL;

        add(*res_h, *res_t, temp_h, temp_t, &new_h, &new_t);

        /*
         * Update result list
         */
        free_linked_list(*res_h);
        *res_h = new_h;
        *res_t = new_t;

        /*
         * Free temporary list
         */
        free_linked_list(temp_h);

        /*
         * Move to next digit of multiplier
         * and increase shift
         */
        ptr2 = ptr2->prev;
        shift++;
    }
}