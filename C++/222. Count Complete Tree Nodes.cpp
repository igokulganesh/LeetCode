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

// Iterative
int countNodes(TreeNode *root)
{
    int count = 0;

    stack<TreeNode *> st; // we can also use queue

    if (root)
        st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        count++;

        if (root->left)
            st.push(root->left);

        if (root->right)
            st.push(root->right);
    }

    return count;
}

// Recursive
int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

/*
Above approach are O(n)
we still reduce them to O(nLogn) due to complete tree
*/
int countNodes(TreeNode *root)
{
}