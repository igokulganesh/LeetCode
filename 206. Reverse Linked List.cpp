// Iterative Method
ListNode* reverseList(ListNode* head) 
{
    ListNode* prev = NULL, *cur = head, *next ;

    while(cur)
    {
        next = cur->next ;
        cur->next = prev ; 
        prev = cur ; 
        cur = next ; 
    } 

    return prev ; 
}
 
// Tricky Recursive Method
ListNode* reverseList(ListNode* head)
{
    if(head == NULL or head->next == NULL)
        return head ; 

    ListNode *rest = reverseList(head->next) ; 

    head->next->next = head ; 

    head->next = NULL ; 

    return rest  ;
}