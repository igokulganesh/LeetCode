#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

// Think, We don't need to change the address we can change the value
