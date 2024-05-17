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

/*
    Idea is simple use Inorder Traversal
    as we know Inorder Traversal of the BST is Sorted
*/

// Iterative-Approach
bool isValidBST(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;

    while (root or !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        if (prev and prev->val >= root->val)
            return false;

        prev = root;
        root = root->right;
    }

    return true;
}

// Recursive Approch
TreeNode *prev = nullptr;

bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        return true;

    if (!isValidBST(root->left))
        return false;

    if (prev and prev->val >= root->val)
        return false;

    prev = root;
    return isValidBST(root->right);
}