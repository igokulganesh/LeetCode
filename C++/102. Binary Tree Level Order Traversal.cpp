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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;

    vector<int> level;
    int level_len;

    queue<TreeNode *> que;

    if (root)
        que.push(root);

    while (!que.empty())
    {
        level_len = que.size();

        while (level_len--)
        {
            root = que.front();
            que.pop();

            level.push_back(root->val);

            if (root->left)
                que.push(root->left);

            if (root->right)
                que.push(root->right);
        }
        result.push_back(level);
        level.clear();
    }

    return result;
}