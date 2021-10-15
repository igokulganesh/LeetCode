void deleteNode(ListNode* node) 
{
    ListNode* del = node->next ; 

    node->val = del->val ; 
    node->next = del->next ; 

    delete del ; 
}

// Think, We don't need to change the address we can change the value