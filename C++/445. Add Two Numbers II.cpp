ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    stack<int> s1, s2 ; 

    while(l1)
    {
        s1.push(l1->val);
        l1 = l1->next ; 
    }
 
    while(l2)
    {
        s2.push(l2->val);
        l2 = l2->next ; 
    }

    int sum = 0 ; 
    ListNode* head = nullptr, *temp ; 
    while(!s1.empty() or !s2.empty() or sum)
    {
        if(!s1.empty())
        {
            sum += s1.top(); 
            s1.pop();
        }

        if(!s2.empty())
        {
            sum += s2.top();
            s2.pop() ; 
        }

        temp = new ListNode(sum%10); 

        temp->next = head ; 

        head = temp ; 

        sum /= 10 ;   
    }

    return head ;
}