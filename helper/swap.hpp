#pragma oncfe

#include <iostream>

/**
 * @brief Swaps places of two elements in an array
 *
 * @param a the element on the left to be swapped to the right
 * @param b the element on the right to be swapped to the left
 */
template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
