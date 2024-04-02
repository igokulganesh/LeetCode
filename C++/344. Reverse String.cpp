#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char> &s)
{
    int l = 0, r = s.size() - 1;
    char c;
    while (l < r)
    {
        c = s[l];
        s[l++] = s[r];
        s[r--] = c;
    }
}