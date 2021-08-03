/*
    Here we use Level Order Traversal
    in each level pickup the last element 
*/
vector<int> rightSideView(TreeNode* root)
{
    if(root == nullptr)
        return {} ; 

    vector<int> res ; 
    
    queue<TreeNode*> q ; 
    q.push(root) ;
    
    TreeNode *temp ; 
    
    while(!q.empty())
    {
        int len = q.size();

        while(len--)
        {
            temp = q.front(); 
            q.pop(); 
            
            if(len == 0)
                res.push_back(temp->val); 

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        } 
    }
    return res ; 
}
