#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> arr;
        auto ptr = candidates.begin();
        while (*ptr)
        {
            for (int i = 0; i < target / *ptr; ++i)
            {
                arr.push_back(*ptr);
            }
            *ptr++;
        }

        auto beg = arr.begin();
        auto end = beg + 1;

        int sum = *beg;

        while (beg < arr.end())
        {
            cout << sum << " ";

            if (sum == target)
                result.push_back(vector<int>(beg, end));

            if (sum < target)
            {

                if (end < arr.end())
                    sum += *end++;
                else
                    break;
            }

            else if (sum >= target)
                sum -= *beg++;
        }

        return result;
    }
};

int main()
{
    vector<int> can({2, 3, 5});
    Solution s;
    s.combinationSum(can, 8);
}