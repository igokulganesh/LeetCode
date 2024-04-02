#include <vector>

using namespace std;

// 11. Container With Most Water
int maxArea(vector<int> &height)
{
    int max_area = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            max_area = max(max_area, (j - i) * min(height[i], height[j]));
        }
    }
    return max_area;
}

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int max_area = INT_MIN;
    while (left < right)
    {
        max_area = max(max_area, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}

// 42. Trapping Rain Water
int trap(vector<int> &height)
{
    int result = 0;
    int n = height.size();
    vector<int> left(n), right(n);

    int max_bar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_bar = max(max_bar, height[i]);
        left[i] = max_bar;
    }

    max_bar = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        max_bar = max(max_bar, height[i]);
        right[i] = max_bar;
    }

    for (int i = 0; i < n; i++)
    {
        result += abs(height[i] - min(left[i], right[i]));
    }

    return result;
}

// 844. Backspace String Compare
bool backspaceCompare(string s, string t)
{
    int i = s.size() - 1, j = t.size() - 1;
    int skipS = 0, skipT = 0;
    while (i >= 0 or j >= 0)
    {
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                i--;
                skipS++;
            }
            else if (skipS > 0)
                i--, skipS--;
            else
                break;
        }
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                j--;
                skipT++;
            }
            else if (skipT > 0)
                j--, skipT--;
            else
                break;
        }

        if (i >= 0 and j >= 0 and s[i] != t[j])
            return false;

        if ((i >= 0) != (j >= 0))
            return false;

        i--;
        j--;
    }
    return true;
}

// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s)
{
    int start = 0;
    int longestCount = 0;
    unordered_set<char> set;

    for (int i = 0; i < s.size(); i++)
    {
        while (set.find(s[i]) != set.end())
            set.erase(s[start++]);

        set.insert(s[i]);
        longestCount = max(longestCount, i - start);
    }
    return longestCount;
}

// 125. Valid Palindrome
bool isPalindrome(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        while (left < s.size() and iswalnum(s[left]) == 0)
            left++;
        while (right >= 0 and iswalnum(s[right]) == 0)
            right--;

        if (left < right and tolower(s[left]) != tolower(s[right]))
            return false;
        left++, right--;
    }

    return true;
}

// 680. Valid Palindrome II
bool validPalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    bool skip = true;

    while (left < right - 1)
    {
        if (s[left] != s[right])
        {
            if (skip)
            {
                skip = false;
                if (s[left + 1] == s[right])
                    left++;
                else if (s[left] == s[right - 1])
                    right--;
            }
            else
                return false;
        }

        left++;
        right--;
    }
    return true;
}

// 206. Reverse Linked List
ListNode *reverseList(ListNode *head)
{
    ListNode *current, *next, *prev;
    current = head;
    prev = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// 92. Reverse Linked List II
ListNode *reverse(ListNode *start, ListNode *end)
{
    ListNode *current = start, *prev = end->next, *next;

    while (current != end)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    end->next = prev;
    return end;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *leftNode, *rightNode, *prev = NULL;

    int pos = 1;
    leftNode = head;
    while (pos++ < left)
    {
        prev = leftNode;
        leftNode = leftNode->next;
    }

    rightNode = leftNode;
    while (pos++ <= right)
        rightNode = rightNode->next;

    ListNode *revHead = reverse(leftNode, rightNode);

    if (prev)
        prev->next = revHead;
    else
        head = revHead;

    return head;
}

// 430. Flatten a Multilevel Doubly Linked List
Node *flatten_util(Node *cur)
{
    Node *next = NULL;
    while (cur and (cur->next or cur->child))
    {
        next = cur->next;
        if (cur->child)
        {
            cur->next = cur->child;
            cur->child->prev = cur;
            cur = flatten_util(cur->child);
            cur->next = next;
            next->prev = cur;
        }
        cur = next;
    }
    return cur;
}

Node *flatten(Node *head)
{
    flatten_util(head);
    return head;
}