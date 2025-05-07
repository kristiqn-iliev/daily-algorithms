#include <iostream>
#include "../../data-structures/vector/vector.hpp"
#include "../../helper/print_arr.hpp"
#include "../../helper/swap.hpp"

int main()
{
    Vector<char> a{'a', 'b', 'b'};
    Vector<char> b(a);

    b.push('c');

    b = a;

    b.push('d');
    b.push('d');

    b = a;

    b = {'a', 'b', '$', 'a', 's'};
    b.print();
}