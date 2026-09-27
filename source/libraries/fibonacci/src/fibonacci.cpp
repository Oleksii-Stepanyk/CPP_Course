#include "fibonacci.hpp"

/* Can be done in one line if only the positive values are allowed ->
-> Skip error handling part or corner case (do no need to handle value that is negative, or bigger than 20). */
int fibonacci_recursive(const int value)
{
    return value <= 1 ? value : fibonacci_recursive(value - 1) + fibonacci_recursive(value - 2);
}

/* Had a thought about storing intermediate products in vector, but what's the point of storing all that mess?
Unless we use vector globally to save values between function calls */
int fibonacci_iterative(const int value)
{
    if (value <= 1)
    {
        return value;
    }

    int f_1 = 0;
    int f_2 = 1;
    int f_3 = 0;

    for (int i = 2; i <= value; i++)
    {
        f_3 = f_1 + f_2;
        f_1 = f_2;
        f_2 = f_3;
    }

    return f_3;
}