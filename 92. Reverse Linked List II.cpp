ListNode* find(ListNode* head, int pos)
{
    ListNode* prev = head ;
    ListNode* cur = head ; 
    while(--pos)
    {
        prev = cur ;  
        cur = cur->next ; 
    }
    return prev ; 
}

ListNode* reverse(ListNode *head, ListNode* end)
{
    ListNode *cur = head, *prev = end->next, *next ; 

    while(cur and cur != end)
    {
        next = cur->next ; 
        cur->next = prev ; 
        prev = cur ; 
        cur = next ; 
    }

    if(cur)
        cur->next = prev ;

    return cur ; 
}

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if(left == 1 and right == 1)
        return head ; 
    
    ListNode *rNode = find(head, right);
    ListNode *lNode = find(head, left);
    
    if(left == 1)
        return reverse(head, rNode->next);
    
    lNode->next = reverse(lNode->next, rNode->next);
        
    return head ; 
}