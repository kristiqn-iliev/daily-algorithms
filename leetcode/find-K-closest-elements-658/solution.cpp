#include <iostream>
#include "../../data-structures/vector/vector.hpp"
#include "vector"
#include "algorithm"

void transform(Vector<int> &myNums, const std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        myNums.push(nums[i]);
    }
}

int *find_x(std::vector<int> &vec, int x)
{
    int *ptr = &vec[0];
    while (*ptr)
    {
        if (*ptr++ == x)
            return ptr - 1;
    }

    return nullptr;
}

int main()
{

    Vector<int> myNums;
    std::vector<int> nums({2, 4, 6, 8, 10});
    int k = 4;
    int x = 6;
    // if x is inside k=k-1;

    int *ptr = &nums[0];
    std::cout << *(ptr);

    int *elem_ptr = find_x(nums, x);
    if (elem_ptr)
    {
        k -= 1;
        transform(myNums, nums);
    }
    else
    {
        nums.push_back(x);
        std::sort(nums.begin(), nums.end());
        transform(myNums, nums);
        elem_ptr = find_x(nums, x);
    }
    while (k > 0)
    {
        std::cout << --k;
    }
}
