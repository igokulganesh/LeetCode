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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *head = nullptr, *cur;
	int carry = 0, sum;

	while (l1 and l2)
	{
		sum = l1->val + l2->val + carry;

		if (!head)
		{
			head = new ListNode(sum % 10);
			cur = head;
		}
		else
		{
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
		}

		carry = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1)
	{
		sum = l1->val + carry;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		carry = sum / 10;
		l1 = l1->next;
	}

	while (l2)
	{
		sum = l2->val + carry;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		carry = sum / 10;
		l2 = l2->next;
	}

	if (carry)
		cur->next = new ListNode(carry);

	return head;
}