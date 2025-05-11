#include <iostream>
#include "../../helper/constants.hpp"
#include "../../data-structures/vector/vector.hpp"

double solution(Vector<int> &nums, unsigned k)
{

    double current = nums.subvector(0, k).total();
    double maxSum = current;
    std::cout << current << std::endl;
    unsigned i = 0;
    for (; i < nums.length() - k; ++i)
    {
        current = current - nums(i) + nums(k + i);

        std::cout << current << std::endl;

        if (maxSum < current)
            maxSum = current;
    }

    current = nums.subvector(i, k + i).total();
    if (maxSum < current)
        maxSum = current;

    return maxSum / k;
}

int main()
{
    Vector<int> vec = {4, 2, 1, 3, 3};
    unsigned k = 2;
    std::cout << solution(vec, k);
}