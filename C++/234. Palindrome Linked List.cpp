#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *get_middle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        slow = slow->next;

    return slow;
}

ListNode *reverse_list(ListNode *head)
{
    ListNode *cur = head, *prev = nullptr, *next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    ListNode *mid = get_middle(head);
    mid = reverse_list(mid);

    while (mid)
    {
        if (head->val != mid->val)
            return false;
        head = head->next;
        mid = mid->next;
    }

    return true;
}

// Solution using Stack
ListNode *get_middle(ListNode *head, stack<ListNode *> &stack)
{
    ListNode *slow = head, *fast = head;

    while (fast and fast->next)
    {
        stack.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        slow = slow->next;

    return slow;
}

bool isPalindrome(ListNode *head)
{
    stack<ListNode *> stack;

    ListNode *mid = get_middle(head, stack);

    while (mid)
    {
        if (mid->val != stack.top()->val)
            return false;
        stack.pop();
        mid = mid->next;
    }
    return true;
}