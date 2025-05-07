#pragma once

#include <iostream>
/**
 * @brief Prints the elements of an one-dimensional array of any primitive type
 *
 * @param data the address of the first element of the array
 * @param size the size of the array
 */
template <typename T>
void print_arr(const T *data, size_t size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}