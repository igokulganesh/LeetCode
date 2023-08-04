bool findTarget(TreeNode* root, int k) 
{
    unordered_set<int> s ; 
    stack<TreeNode*> st ;

    st.push(root); 

    while(!st.empty()) 
    {
        root = st.top();
        st.pop(); 
        if(s.find(k-root->val) != s.end())
            return true ; 
        s.insert(root->val);

        if(root->left)
            st.push(root->left); 

        if(root->right)
            st.push(root->right); 
    }

    return false ; 
}