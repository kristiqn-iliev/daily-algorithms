#include <iostream>
#include "../../data-structures/vector/vector.hpp"

void initialize_triangle(Vector<Vector<long long>> &pascal, unsigned const rows, unsigned cols)
{
    if (cols > rows)
        cols = rows;
    for (unsigned i = 2; i < rows; ++i)
    {
        unsigned index;
        i < cols ? index = i : index = cols;
        Vector<long long> row;
        row.push(1);
        for (int j = 1; j < index; ++j)
        {
            row.push(pascal(i - 1)(j - 1) + pascal(i - 1)(j));
        }
        if (i < cols)
            row.push(1);

        pascal.push(row);
    }
}

long long solution()
{
    const unsigned int ROWS = 110;
    Vector<Vector<long long>> pasc = {{1}, {1, 1}};

    unsigned m = 104;
    unsigned n = 5;

    if (m == 1 || n == 1)
        return 1;

    unsigned row = m + n - 2;
    unsigned col;
    m >= n ? col = n - 1 : m - 1;

    initialize_triangle(pasc, ROWS, col + 1);

    for (int i = 0; i < 110; ++i)
    {
        pasc(i).print();
    }

    return pasc(row)(col);
}

int main()
{
    std::cout << solution();
}