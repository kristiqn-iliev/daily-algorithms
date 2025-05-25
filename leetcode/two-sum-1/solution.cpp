#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        using index = unsigned;
        using value = int;
        map<value, index> map;
        for (index i = 0; i < nums.size(); ++i)
        {
            map.insert({nums[i], i});
        }

        sort(nums.begin(), nums.end());

        auto start = nums.begin();
        auto end = nums.end() - 1;

        std::cout << map[*end] << endl;

        while (start <= end)
        {
            std::cout << "values:" << "start:" << *start << "end:" << *end << endl;
            std::cout << "indices:" << "start:" << map[*start] << "end:" << map[*end] << endl;

            if (*start + *end > target)
                --end;

            else if (*start + *end < target)
                ++start;

            else
            {
                result.push_back(map[*start]);
                result.push_back(map[*end]);
                break;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> a({3, 3, 3});
    Solution sol;

    vector<int> result = sol.twoSum(a, 6);
    cout << result[0] << " " << result[1];
}