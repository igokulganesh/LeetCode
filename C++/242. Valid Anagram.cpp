#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (hash[i])
            return false;

    return true;
}