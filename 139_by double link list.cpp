#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
 node *head=NULL;
 
int ele;
int choice;
int main()
{
    void create();
    void display();
    void search();
    void insertBeg();
    void insertEnd();
    void inBetween();
    void deleteBeg();
    void deleteEnd();
    void printReverse();
    void reverse();
    void deleteSpecific();
    do
    {
        cout<<"enter 1 for create linked list"<<endl;
        cout<<"enter 2 for displaying the link list"<<endl;
        cout<<"enter 3 for search an element in linked list"<<endl;
        cout<<"enter 4 for insertion at begining "<<endl;
        cout<<"enter 5 for insertion at end "<<endl;
        cout<<"enter 6 for insertion after a specific value"<<endl;
        cout<<"enter 7 for deleteion from beginning of the list"<<endl;
        cout<<"enter 8 for deletion from end of the list"<<endl;
        cout<<"enter 9 for deletion after a specific value"<<endl;
        cout<<"enter 10 for printing reverse of  the linked list"<<endl;
        cout<<"enter 11 for exit"<<endl;
        
        cin>>choice;
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            insertBeg();
            break;
            case 5:
            insertEnd();
            break;
            case 6:
            inBetween();
            break;
           case 7:
            	deleteBeg();
            	break;
        	case 8:
      		 deleteEnd();
        	break;
        	case 9:
			deleteSpecific();
			break;
			case 10:
			printReverse();	
      
        }
    }while(choice!=11);

    return 0;
}
void create()
{
    cout<<"enter the element  ";
    cin>>ele;
    if(head==NULL)
    {
    	node *temp=new node;
        temp->data=ele;
        temp->pre=NULL;
        temp->next=NULL;
        head=temp;
    }
    else
    {
    	node *temp=new node;
       temp->data=ele;
       temp->next=head;
       temp->pre=NULL;
       head->pre=temp;
       head=temp;
    }
}
void display()
{
	 node *temp=head;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;;
        }
    }
    else
    {
        cout<<"list is empty";
    }
}
void search()
{
    cout<<"enter the number you want to search  ";
    cin>>ele;
    node *temp=head;
    if(head==NULL)
    cout<<"list is empty";
    else
    {
        while(temp!=NULL &&temp->data!=ele)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        cout<<"number not exist"<<endl;
        else
        cout<<"number exist"<<endl;
    }
}
void insertBeg()
{
    cout<<"insertion at beginning"<<endl;
    cout<<"enter the element  ";
    cin>>ele;
    node *temp=new node;
    temp->data=ele;
    temp->pre==NULL;
    temp->next=head;
    head->pre=temp;
    head=temp;
}
void insertEnd()
{
    cout<<"insertion at end"<<endl;;
    cout<<"enter the element ";
    cin>>ele;
    node *temp=new node;
    temp->data=ele;
    temp->next=NULL;
    temp->pre=NULL;
    node *p=head;
    if(head==NULL)
        head=temp;
    else
    {
       while(p->next!=NULL)
        {   
            p=p->next;
        }    
        p->next=temp;
        temp->pre=p;
    }   
}
void inBetween()
{
    int num;
    //cout<<"insertion after specific value ";
    cout<<"enter the element after which you want to insert ";
    cin>>num;
    cout<<"enter element you want to insert ";
    cin>>ele;
    node *temp=new node;
    if(head==NULL)
    cout<<"list is empty";
    else
    {
        node *p=head;
        while(p->next!=NULL &p->data!=num)
        p=p->next;
        if(p->next==NULL)
        {
        	temp->data=ele;
        	p->next=temp;
        	temp->pre=p;
        	temp->next==NULL;
        }
        else
        {
            temp->data=ele;
            temp->next=p->next;
            temp->pre=p;
             p->next=temp;
            (temp->next)->pre=temp;
        }
    }

}
void deleteBeg()
{
	if(head==NULL)
		cout<<"list is empty";
	else
	{
		node *temp=head;
		head=head->next;
		head->pre=NULL;
		delete temp;
	}	
}
void deleteEnd()
{
	node *temp=head;
	if(head==NULL)
	cout<<"list is empty";
	else
	{
		node *pre;
		while(temp->next!=NULL)
		{
			pre=temp;
			temp=temp->next;
		}
		if(temp==head)
			head==NULL;
		else
		pre->next=NULL;
	}
	delete temp;
}
void deleteSpecific()
{
	node *temp=head;
	cout<<"enter the element you want to delete";
	cin>>ele;
	if(head==NULL)
		cout<<"list is empty";
	else
	{
		while(temp->next!=NULL && temp->data!=ele)
		temp=temp->next;
		if(temp->data!=ele)
		cout<<"element not found";
		else if(temp==head)
		{
			head=head->next;
			head->pre=NULL;

		}
		else 
		{
			(temp->pre)->next=temp->next;
			(temp->next)->pre=temp->pre;
		}
	}
	delete temp;
}
//     ------------
//     |  ^|  ^|  ^
//   --1 ->2 ->3 ->4--
//   			  Head
void printReverse()
{
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->pre;
	}
}

void reverse()
{
	// some error in this function 
	node *temp1=head;
	node *temp2=new node;
	while(temp1!=NULL)
	{
		if(temp1->pre==NULL)
		{
			temp2=temp1->next;
			node *temp3=temp1;
			temp1->pre=temp1->next;
			temp1->next->pre=temp1->next->next;
			temp1->next->next=temp1;
			temp1->next=NULL;
			temp1=temp2;
		}
		else if(temp1->next->next==NULL)
		{
			temp2=temp1->next;
			node *temp3=temp1->next->pre;
			
			temp1->next->pre=temp1->next->next;
			temp1->next->next=temp3;
//			temp1->pre=temp1->next;
//			temp1->next->next=temp1;
				
			head=temp2;
			temp1=NULL;
		}
		else
		{
			temp2=temp1->next;

//			temp1->pre=temp1->next;
//			temp1->next->next=temp1;
			node *temp3=temp1->next->pre;
			temp1->next->pre=temp1->next->next;
			
			temp1->next->next=temp3;	
			temp1=temp2;
		}
	}
}
