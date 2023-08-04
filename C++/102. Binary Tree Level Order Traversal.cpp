vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> res ; 
    vector<int> sub ; 

    if(root == NULL)
        return res ; 

    queue<TreeNode*> q ; 
    q.push(root);

    TreeNode *temp ; 
    int level ; 

    while(!q.empty())
    {
        sub.clear();
        level = q.size() ;
        while(level--)
        {
            temp = q.front();
            q.pop(); 
            sub.push_back(temp->val);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        res.push_back(sub); 
    }    

    return res ; 
}