#include <iostream>
#include "../../data-structures/vector/vector.hpp"
#include "../../helper/constants.hpp"
void findMax(int &max, Vector<int> vec, Vector<int> &vecSol)
{
    if (vec.total() > max)
    {
        max = vec.total();
        vecSol = vec;
    }

    if (vec.length() < 2)
        return;

    findMax(max, vec.subvector(1), vecSol);
    findMax(max, vec.subvector(0, vec.length() - 1), vecSol);
}

int solution()
{
    int max = MY_INT_MIN;
    Vector<int> vec{-84, -87, -78, -16, -94, -36, -87, -93, -50, -22, -63, -28, -91, -60, -64, -27, -41, -27, -73, -37, -12, -69, -68, -30, -83, -31, -63, -24, -68, -36, -30, -3, -23, -59, -70, -68, -94, -57, -12, -43, -30, -74, -22, -20, -85, -38, -99, -25, -16, -71, -14, -27, -92, -81, -57, -74, -63, -71, -97, -82, -6, -26, -85, -28, -37, -6, -47, -30, -14, -58, -25, -96, -83, -46, -15, -68, -35, -65, -44, -51, -88, -9, -77, -79, -89, -85, -4, -52, -55, -100, -33, -61, -77, -69, -40, -13, -27, -87, -95, -40};
    Vector<int> vecSol;
    findMax(max, vec, vecSol);
    std::cout << max;
    return 0;
}

int main()
{
    solution();
}