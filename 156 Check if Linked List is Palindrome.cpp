// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *temp=head;
        int le=1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            le++;
        }
        if(le<=1)
        return 1;
        
        temp=head;
        int mid=le/2;
        
        
        
        
        Node *second=head;
        Node *first;
        Node *pre;
        while(mid)
        {
            pre=second;
            second=second->next;
            mid--;
        }
        
        mid=le/2;
        
        if(le%2!=0)
        second=second->next;
        
        first=head;
        pre->next=NULL;
//        second=temp;
        
        
        Node *current = second;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;

			// Reverse current node's pointer
			current->next = prev;

			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		second = prev;
		
		
//		while(second!=NULL)
//		{
//		
//			cout<<second->data;
//			second=second->next;
//		}
//		
//		while(first!=NULL)
//		{
//		
//			cout<<first->data;
//			first=first->next;
//		}
//		cout<<"  "<<mid;



		while(mid)
		{
		    if(first->data!=second->data)
		    return 0;
		    else
		    continue;
		    
		    first=first->next;
		    second=second->next;
		    mid--;
		}
		
		return 1;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
