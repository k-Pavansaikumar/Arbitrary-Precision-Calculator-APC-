# Arbitrary Precision Calculator (APC)

## Project Definition

Arbitrary Precision Calculator is a C-based application that performs arithmetic operations on very large numbers which exceed the storage capacity of standard data types.

The project represents large numbers using Doubly Linked Lists, where each node stores a block of digits. It supports mathematical operations like addition, subtraction, multiplication, and division using manual calculation algorithms.

## Features

- Perform arithmetic operations on large numbers
- Supports Addition, Subtraction, Multiplication, and Division
- Handles numbers beyond normal integer limits
- Stores numbers using Doubly Linked List representation
- Uses command-line arguments for input operations
- Supports positive and negative number calculations
- Dynamic memory allocation for efficient storage

## Technologies Used

- C Programming
- Data Structures
- Doubly Linked List
- Pointers
- Dynamic Memory Allocation
- Command Line Arguments
- Modular Programming

## Learning Outcomes

- Understanding arbitrary precision arithmetic implementation
- Working with doubly linked lists in C
- Performing mathematical operations without built-in data limits
- Handling memory allocation and deallocation
- Implementing carry and borrow based arithmetic logic
- Understanding modular programming approach

## How to Run

Compile:

make

Run:

./a.out <number1> <operator> <number2>

## Examples

Addition:
./a.out 123456789123456789 + 987654321987654321

Subtraction:
./a.out 987654321987654321 - 123456789123456789

Multiplication:
./a.out 123456789 * 987654321

Division:
./a.out 1000000000000 / 1000

## Supported Operations

+  Addition

-  Subtraction

*  Multiplication

/  Division
