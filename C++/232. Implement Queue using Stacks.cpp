#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;

    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (s1.empty())
            s1.push(x);
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = s1.top();
        s1.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};
