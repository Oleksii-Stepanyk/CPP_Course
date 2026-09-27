#include "fibonacci.hpp"

#include <print>

int main(int argc, char **argv)
{
    std::print("{}\n", "Recursive");
    std::print("{}\n", fibonacci_recursive(2));
    std::print("{}\n", fibonacci_recursive(10));
    std::print("\n{}\n", "Iterative");
    std::print("{}\n", fibonacci_iterative(2));
    std::print("{}\n", fibonacci_iterative(10));
    return 0;
}