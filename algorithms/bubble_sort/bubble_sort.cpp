#include <iostream>
#include "../../data-structures/vector/vector.hpp"
#include "../../helper/print_arr.hpp"
#include "../../helper/swap.hpp"

void bubble_sort(Vector<int> &input)
{
    for (unsigned j = 1; j < input.length(); ++j)
    {
        for (unsigned i = 0; i < input.length() - j; ++i)
        {
            if (*input[i] > *input[i + 1])
                swap(*input[i], *input[i + 1]);
        }
    }
}