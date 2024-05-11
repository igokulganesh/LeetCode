#include <bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> stack;
    vector<bool> is_removed(s.size(), false);
    string valid_str = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stack.push(i);
        else if (s[i] == ')')
            if (stack.empty())
                is_removed[i] = true;
            else
                stack.pop();
    }

    while (!stack.empty())
    {
        is_removed[stack.top()] = true;
        stack.pop();
    }

    for (int i = 0; i < s.size(); i++)
        if (!is_removed[i])
            valid_str += s[i];

    return valid_str;
}
