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

int size(ListNode *head)
{
    int n = 0;
    while (head)
    {
        head = head->next;
        n++;
    }
    return n;
}

ListNode *move(ListNode *head, int n)
{
    while (n--)
        head = head->next;
    return head;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int s1 = size(headA);
    int s2 = size(headB);

    if (s1 > s2)
        headA = move(headA, s1 - s2);
    else
        headB = move(headB, s2 - s1);

    ListNode *intersect_node = nullptr;

    while (headA and headB)
    {
        if (headA == headB)
        {
            intersect_node = headA;
            break;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return intersect_node;
}