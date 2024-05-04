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

// Recursion Solution
void inorderTraversal(TreeNode *root, vector<int> &result)
{
    if (root)
    {
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    inorderTraversal(root, result);
    return result;
}

// Iteration
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;

    stack<TreeNode *> s;

    while (1)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }

        if (s.empty())
            break;

        root = s.top();
        s.pop();

        result.push_back(root->val);
        root = root->right;
    }

    return result;
}
