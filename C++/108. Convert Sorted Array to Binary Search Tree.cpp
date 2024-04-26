#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}
