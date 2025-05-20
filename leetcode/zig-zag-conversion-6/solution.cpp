#include <iostream>
#include <string>

int main()
{
    std::string str = "PAYPALISHIRING";
    unsigned n = 4;
    std::string result = "";

    for (int i = 0; i < str.length(); i += 2 * (n - 1))
    {
        result.push_back(str[i]);
    }

    unsigned k;
    for (int j = 1; j < n - 1; j++)
    {
        k = 1;
        for (int i = j; i < str.length(); i += 2 * (n - 1))
        {
            result.push_back(str[i]);
            if (k * 2 * (n - 1) - j < str.length())
                result.push_back(str[k * 2 * (n - 1) - j]);
            ++k;
        }
    }

    for (int i = n - 1; i < str.length(); i += 2 * (n - 1))
    {
        result.push_back(str[i]);
    }

    std::cout << result;
}