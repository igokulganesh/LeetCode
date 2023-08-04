ListNode *detectCycle(ListNode *head) 
{
    ListNode* slow = head, *fast = head ; 

    while(fast and fast->next)
    {
        slow = slow->next ; 
        fast = fast->next->next ; 

        if(slow == fast)
        {
            ListNode* start = head ;
            while(slow != start)
            {
                slow = slow->next ;
                start = start->next ; 
            }
            return start ; 
        }
    }   
    return NULL ;  
}