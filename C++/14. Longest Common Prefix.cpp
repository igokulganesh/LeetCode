#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());

    string result = "";
    string first = strs[0], last = strs.back();

    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
            break;
        result += first[i];
    }

    return result;
}