// { Driver Code Starts
/* Program to split a circular linked list into two halves */


#include<stdio.h> 
#include<stdlib.h> 
 
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
 struct Node* newNode(int key)
{
    struct Node *temp = new Node(key);
    
    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

 
/* Driver program to test above functions */
int main()
{
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
	   struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
	   scanf("%d",&n);
	   scanf("%d",&x);
	   head=new Node(x);
	   temp=head;
	   for(i=0;i<n-1;i++){
	   scanf("%d",&x);
	   
	   temp->next=new Node(x);
	   
	   temp=temp->next;
	       
	   }
       
       temp->next=head;
  
       splitList(head, &head1, &head2);
  
     // printf("\nFirst Circular Linked List");
      printList(head1);  
 
     // printf("\nSecond Circular Linked List");
      printList(head2);  
   
   }
  return 0;
}
// } Driver Code Ends


/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *first=head;
    Node *head11_ref=head;
    Node *head22_ref=head;
    head22_ref=head22_ref->next;
    int l=1;
    int m;
    while(head22_ref->next!=head)
    {
        head22_ref=head22_ref->next;
        l++;
    }
    if(l>1)
    l=l+1;
    else
    {
        head11_ref->next=NULL;
        head22_ref->next=NULL;
    }
    
    if(l%2==0)
    m=l/2-1;
    else
    m=l/2;
    
    head22_ref=head;
    while(l>1)
    {
        head22_ref=head22_ref->next;  
        l--;
    }
    head22_ref->next=NULL;
    head22_ref=head;
    Node *temp=head;
    if(l%2==0)
    {
        while(m>0)
        {
            head11_ref=head11_ref->next;
            m--;
        }
        m=l/2-1;
        while(m>=0)
        {
            head22_ref=head22_ref->next;  
            m--;
        }
        head11_ref->next=NULL;
        head11_ref=head;
        *head1_ref=head11_ref;
        *head2_ref=head22_ref->next;
    }
    else
    {
        while(m>0)
        {
            head11_ref=head11_ref->next;
            m--;
        }
        m=l/2;
        while(m>=0)
        {
            head22_ref=head22_ref->next;  
            m--;
        }
        *head2_ref=head22_ref;
        head11_ref->next=NULL;
        head11_ref=head;
        *head1_ref=head11_ref;
    }
    
}
