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
    Here we use Level Order Traversal
    in each level pickup the last element
*/
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;

    queue<TreeNode *> que;
    int level;

    if (root)
        que.push(root);

    while (!que.empty())
    {
        level = que.size();

        while (level--)
        {
            root = que.front();
            que.pop();

            if (level == 0)
                res.push_back(root->val);

            if (root->left)
                que.push(root->left);

            if (root->right)
                que.push(root->right);
        }
    }
    return res;
}
