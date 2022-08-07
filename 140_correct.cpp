// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        // Initialize current, previous and
        // next pointers
        node *head1=head;
        node *current = head;
        node *prev = NULL;
        node *next = NULL;
 
        int j=1;
        int p=0;
        int no_of_node=1;
        while(current->next!=NULL)
        {
            current=current->next;
            no_of_node++;
        }
        
        current=head;
        
        while (current != NULL) {
            // Store next
            
            if(j%(k+1)!=0)
            {
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
            j++;
            }
            else
            {
                j++;
                if(p==0)
                {
                    head=prev;
                    prev=NULL;
                    p++;
                    
                }
                else
                {
                    head1->next=prev;
                    while(prev->next!=NULL)
                    {
                        prev=prev->next;
                    }
                    head1=prev;
                    prev=NULL;
                }
            }
        }
        if(no_of_node==k)
        {
        	head=prev;
            return head;
		}
        head1->next=prev;
        head1=prev;
        prev=NULL;
        return head;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}
