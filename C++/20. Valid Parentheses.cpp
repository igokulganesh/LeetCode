#include <bits/stdc++.h>

using namespace std;

bool isOpen(char ch)
{
    return (ch == '[' or ch == '{' or ch == '(');
}

bool isMatch(char open, char close)
{
    switch (open)
    {
    case '{':
        return (close == '}');
    case '[':
        return (close == ']');
    case '(':
        return (close == ')');
    }
    return false;
}

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (isOpen(c))
            st.push(c);
        else if (!st.empty() and isMatch(st.top(), c))
            st.pop();
        else
            return false;
    }

    return st.empty();
}