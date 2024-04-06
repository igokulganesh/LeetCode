

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Method
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr, *cur = head, *next;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

// Tricky Recursive Method
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    ListNode *rest = reverseList(head->next);

    head->next->next = head;

    head->next = nullptr;

    return rest;
}
