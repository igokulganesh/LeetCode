
ListNode* middleNode(ListNode* head) 
{
    ListNode *fast = head, *slow = head ; 

    while(fast and fast->next)
    {
        fast = fast->next->next ; 
        slow = slow->next ; 
    }

    return slow ;
}