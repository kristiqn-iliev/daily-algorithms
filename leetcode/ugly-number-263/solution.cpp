#include <iostream>
class Solution
{
public:
    bool isUgly(int n)
    {
        while (n % 5 == 0)
        {
            n /= 5;
        }

        while (n % 3 == 0)
        {
            n /= 3;
        }

        while (n % 2 == 0)
        {
            n /= 2;
        }

        return n == 1;
    }
};

int main()
{
    Solution s;
    std::cout << s.isUgly(14);
    return 0;
}