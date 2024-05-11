#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flattenRec(Node *cur)
{
    Node *prev = nullptr;
    Node *next;

    while (cur)
    {
        if (cur->child)
        {
            next = cur->next; // Storing next value

            cur->next = cur->child; // make cur next as child

            cur->child->prev = cur; // make child prev as cur

            Node *NewTail = flattenRec(cur->child); // recursive call for flattern child level and return tail of that list

            NewTail->next = next; // make new list next to cur next

            if (next)
                next->prev = NewTail; // make next prev as new list end

            cur->child = nullptr;

            cur = next;
            prev = NewTail;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return prev; // return current list tails
}

Node *flatten(Node *head)
{
    if (head)
        flattenRec(head);
    return head;
}