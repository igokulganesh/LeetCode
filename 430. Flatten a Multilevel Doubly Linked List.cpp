Node* flattenRec(Node* head) 
{   
    if(head == NULL)
        return NULL ; 

    Node* cur = head ; 
    Node* prev = head ;
    Node* next = NULL; 

    while(cur)
    {
        next = cur->next ; 
        if(cur->child)
        {
            Node* next = cur->next ; // Storing next value 

            cur->next = cur->child ; // make cur next as child 

            cur->child->prev = cur ;  // make child prev as cur

            Node* NewTail = flattenRec(cur->next); // recursive call for flattern child level and return tail of that list 

            NewTail->next = next ; // make new list next to cur next 

            if(next)
                next->prev = NewTail ; // make next prev as new list end 

            cur->child = nullptr ; 

            cur = next ; 
            prev = NewTail ;
        }
        else
        {
            prev = cur ; 
            cur = cur->next ; 
        }
    }

    if(cur == NULL)
        return prev ; 

    return head ; 
}

Node* flatten(Node* head)
{
    if(head)
        flattenRec(head);
    return head ; 
}