#include <bits/stdc++.h>

using namespace std;

// normal way
class MinStack
{
    list<int> stack;
    int min_val;

public:
    MinStack() : min_val(INT_MAX) {}

    void push(int val)
    {
        min_val = min(min_val, val);
        stack.push_back(val);
    }

    void pop()
    {
        int val = stack.back();
        stack.pop_back();
        if (val == min_val)
        {
            min_val = INT_MAX;
            for (int x : stack)
                min_val = min(x, min_val);
        }
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min_val;
    }
};

// good way
class MinStack
{
    list<pair<int, int>> stack;

public:
    MinStack() {}

    void push(int val)
    {
        int min_val = min(this->getMin(), val);
        stack.push_back({val, min_val});
    }

    void pop()
    {
        pair val = stack.back();
        stack.pop_back();
    }

    int top()
    {
        return stack.back().first;
    }

    int getMin()
    {
        if (stack.empty())
            return INT_MAX;
        return stack.back().second;
    }
};
