#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s)
{
    int map[26] = {0};

    for (auto &c : s)
        map[c - 'a']++;

    for (int i = 0; i < s.size(); i++)
    {
        if (map[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}
