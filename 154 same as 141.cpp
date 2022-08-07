class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(!head) return true;
        
        //using two pointers and moving one pointer(slow) by one node and 
        //another pointer(fast) by two nodes in each iteration.
        Node* fast = head->next;
        Node* slow = head;
        
        while( fast != slow)
        {
            //if the node pointed by first pointer(fast) or the node 
            //next to it is null, we return false.
            if( !fast || !fast->next ) 
            return false;
            
            fast=fast->next->next;
            slow=slow->next;
        }
        //if we reach here it means both the pointers fast and slow point to 
        //same node which shows the presence of loop so we return true.
        return true;
    }
};

