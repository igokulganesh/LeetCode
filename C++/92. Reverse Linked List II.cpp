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

ListNode *find(ListNode *head, int pos)
{
    while (--pos > 0)
        head = head->next;

    return head;
}

ListNode *reverse(ListNode *head, ListNode *end)
{
    ListNode *cur = head, *prev = end->next, *next;

    while (cur and cur != end)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    if (cur)
        cur->next = prev;

    return cur;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *lNode = find(head, left - 1);          // Finding Prev of Left
    ListNode *rNode = find(lNode, right - left + 1); // Finding right

    if (left == 1)
        return reverse(head, rNode);

    lNode->next = reverse(lNode->next, rNode->next);

    return head;
}
