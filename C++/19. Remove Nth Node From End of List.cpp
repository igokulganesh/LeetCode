ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode *fast = head ; 

    while(n--)
        fast = fast->next ; 
    
    ListNode *prev = head ; 

    while(fast and fast->next)
    {
        fast = fast->next ; 
        prev = prev->next ; 
    }

    if(fast == NULL)
    {
        fast = head ; 
        head = head->next ; 
    }
    else
    {
        fast = prev->next ; 
        prev->next = prev->next->next ; 
    } 
    
    fast->next = NULL ; 
    delete fast ; 

    return head ; 
}