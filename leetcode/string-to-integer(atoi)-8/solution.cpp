#include <iostream>
#include <sstream>

int atoi()
{

    char *str;
    str = new char[15];
    str[0] = ' ';
    str[1] = ' ';
    str[2] = ' ';
    str[3] = ' ';
    str[4] = '-';
    str[5] = '2';
    str[6] = '1';
    str[7] = '4';
    str[8] = '7';
    str[9] = '4';
    str[10] = '8';
    str[11] = '3';
    str[12] = '6';
    str[13] = '4';
    str[14] = '9';

    bool isNegative = 0;

    char *ptrStart = str;
    while (*ptrStart == ' ')
        ptrStart++;

    char *ptrEnd = ptrStart;
    while (*ptrEnd >= '0' && *ptrEnd <= '9' || (ptrEnd == ptrStart && *ptrEnd == '-') || (ptrEnd == ptrStart && *ptrEnd == '+'))
        ptrEnd++;

    if (*ptrStart == '-')
    {
        isNegative = true;
        ptrStart++;
    }
    if (*ptrStart == '+')
        ptrStart++;

    long result = 0;
    unsigned int length = ptrEnd - ptrStart;

    if (length > 10)
    {
        if (isNegative)
        {
            return 1 << 31;
        }

        else
            return ~(1 << 31);
    }

    unsigned k = 1;

    while (ptrStart != ptrEnd)
    {
        result += int(*(--ptrEnd) - '0') * k;
        k *= 10;
    }
    if (isNegative)
    {
        result *= -1;
    }

    std::cout << length << " ";
    if (length == 10)
    {
        std::cout << result;
        if (result > ~(1 << 31))
            return ~(1 << 31);

        if (result < (1 << 31))
            return 1 << 31;
    }

    int finalResult = result;

    return finalResult;
}

int main()
{
    std::cout << atoi();
}

