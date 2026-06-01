#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Node structure for doubly linked list */
typedef struct cal
{
    int data;
    struct cal *prev;
    struct cal *next;
} cal;

/* Linked list functions */
void insert_at_beginning(cal **head, cal **tail, int data);
void free_linked_list(cal *head);
void print_list(cal *head, int is_negative);
int compare_linked_lists(cal *head1, cal *head2);
void remove_leading_zeros(cal **head);
void insert_at_end(cal **head, cal **tail, int data);

void create_linked_list_from_string(cal **head, cal **tail,
                                    const char *number,
                                    int *is_negative);

/* Arithmetic functions */
void add(cal *head1, cal *tail1, cal *head2, cal *tail2,
         cal **head_result, cal **tail_result);

void sub(cal *head1, cal *tail1, cal *head2, cal *tail2,
         cal **head_result, cal **tail_result);

void multiply(cal *head1, cal *tail1, cal *head2, cal *tail2,
              cal **head_result, cal **tail_result);

void divide(cal *head1, cal *tail1, cal *head2, cal *tail2,
            cal **head_result, cal **tail_result);

/* Validation */
int read_and_validation(int argc, char *argv[]);

extern int result_sign_flag;

#endif