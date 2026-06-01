/*********************************************************************************************************************
* Project Title: Arbitary precision calculator(APC)
* Name: K Pavan Sai Kumar
* Description: This project implements arithmetic operations on large numbers using doubly linked lists in C.
Each node stores a block of digits (base 10000) to handle numbers beyond standard data types.
It supports addition, subtraction, multiplication, and division using manual calculation logic.
The program takes input from the command line and displays the result in proper numeric format.
***********************************************************************************************************************/

#include "header.h"

/* 
 * Global flag to indicate result sign
 * 0 → positive
 * 1 → negative
 */
int result_sign_flag = 0;

int main(int argc, char *argv[])
{
    /*
     * Step 1: Validate command-line arguments
     * Expected format: ./a.out <num1> <op> <num2>
     */
    if (!read_and_validation(argc, argv))
        return 0;

    /*
     * Step 2: Initialize linked list pointers
     * h1, t1 → first number
     * h2, t2 → second number
     * res_h, res_t → result
     */
    cal *h1 = NULL, *t1 = NULL;
    cal *h2 = NULL, *t2 = NULL;
    cal *res_h = NULL, *res_t = NULL;

    /*
     * neg1, neg2 → store sign of input numbers
     */
    int neg1 = 0, neg2 = 0;

    /*
     * Step 3: Convert input strings into linked lists
     * Each node stores 4 digits (base 10000)
     */
    create_linked_list_from_string(&h1, &t1, argv[1], &neg1);
    create_linked_list_from_string(&h2, &t2, argv[3], &neg2);

    /*
     * Step 4: Extract operator (+, -, *, /)
     */
    char op = argv[2][0];

    /*
     * Step 5: Perform operation based on operator
     */
    if (op == '+')
    {
        /*
         * Addition:
         * Result is negative only if signs are different
         */
        add(h1, t1, h2, t2, &res_h, &res_t);
        result_sign_flag = (neg1 != neg2);
    }
    else if (op == '-')
    {
        /*
         * Subtraction:
         * Compare both numbers first
         */
        int cmp = compare_linked_lists(h1, h2);

        if (cmp >= 0)
        {
            /*
             * If first ≥ second:
             * normal subtraction
             */
            sub(h1, t1, h2, t2, &res_h, &res_t);
            result_sign_flag = 0;
        }
        else
        {
            /*
             * If first < second:
             * reverse subtraction and mark result negative
             */
            sub(h2, t2, h1, t1, &res_h, &res_t);
            result_sign_flag = 1;
        }
    }
    else if (op == '*')
    {
        /*
         * Multiplication:
         * Result is negative if signs are different
         */
        multiply(h1, t1, h2, t2, &res_h, &res_t);
        result_sign_flag = (neg1 != neg2);
    }
    else if (op == '/')
    {
        /*
         * Division:
         * Result is negative if signs are different
         */
        divide(h1, t1, h2, t2, &res_h, &res_t);
        result_sign_flag = (neg1 != neg2);
    }

    /*
     * Step 6: Remove unnecessary leading zeros
     * Example: 000123 → 123
     */
    remove_leading_zeros(&res_h);

    /*
     * If result becomes NULL, treat it as 0
     * and reset sign to positive
     */
    if (res_h == NULL)
        result_sign_flag = 0;

    /*
     * Step 7: Print result with correct sign
     */
    print_list(res_h, result_sign_flag);

    /*
     * Step 8: Free all allocated memory
     */
    free_linked_list(h1);
    free_linked_list(h2);
    free_linked_list(res_h);

    return 0;
}
