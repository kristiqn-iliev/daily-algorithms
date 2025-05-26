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

        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                result.push_back(map.at(target - nums[i]));
                result.push_back(i);
                return result;
            }
            else
            {
                map.insert({nums[i], i});
            }
        }

        return result;
    }
};

int main()
{
    vector<int> a({3, 11, 8, 15});
    Solution sol;

    vector<int> result = sol.twoSum(a, 18);
    cout << result[0] << " " << result[1];
}