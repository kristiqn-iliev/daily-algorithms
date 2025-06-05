#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m;
        set<char> set;

        for (int i = 0; i < s.length(); ++i)
        {
            if (m.find(s[i]) == m.end())
            {
                if (set.find(t[i]) != set.end())
                    return false;

                m.insert({s[i], t[i]});
                set.insert(t[i]);
            }

            else
            {
                auto it = m.find(s[i]);
                if (it->second != t[i])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isIsomorphic("bada", "bpdp");
    return 0;
}
