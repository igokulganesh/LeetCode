#include <bits/stdc++.h>

using namespace std;

bool backspaceCompare(string s, string t)
{
    int i = s.size() - 1;
    int j = t.size() - 1;
    int bS = 0, bT = 0;
    while (i >= 0 or j >= 0)
    {
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                i--;
                bS++;
            }
            else if (bS > 0)
            {
                bS--;
                i--;
            }
            else
                break;
        }

        while (j >= 0)
        {

            if (t[j] == '#')
            {
                j--;
                bT++;
            }
            else if (bT > 0)
            {
                j--;
                bT--;
            }
            else
                break;
        }

        if (i >= 0 and j >= 0 and s[i] != t[j])
            return false;

        if ((i >= 0) != (j >= 0))
            return false;

        i--;
        j--;
    }

    return true;
}

// Removing every # and do backspace and then compare (Not Recommended)
bool backspaceCompare(string &s, string &t)
{
    int i;

    for (i = 0; i < s.size(); i++)
    {
        if (i > 0 and s[i] == '#')
        {
            s.erase(i, 1);
            s.erase(i - 1, 1);
            i -= 2;
        }
        else if (s[0] == '#')
        {
            s.erase(0, 1);
            i--;
        }
    }

    for (i = 0; i < t.size(); i++)
    {
        if (i > 0 and t[i] == '#')
        {
            t.erase(i, 1);
            t.erase(i - 1, 1);
            i -= 2;
        }
        else if (t[0] == '#')
        {
            t.erase(0, 1);
            i--;
        }
    }

    return (s == t);
}
