#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++, right--;
    }
    return true;
}

void partition(string s, vector<string> &cur, vector<vector<string>> &res)
{
    if (s.empty())
    {
        res.push_back(cur);
        return;
    }

    for (int i = 1; i <= s.size(); i++)
    {
        string left(s.begin(), s.begin() + i);

        if (isPalindrome(left))
        {
            cur.push_back(left);

            string right(s.begin() + i, s.end());
            partition(right, cur, res);

            cur.pop_back(); // Backtracking
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> cur;
    partition(s, cur, res);
    return res;
}