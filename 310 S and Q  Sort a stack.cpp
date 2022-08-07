// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &stack, int num){
    
    if(stack.empty() ||(!stack.empty()&& stack.top() < num))
    {
       stack.push(num);
       return;
    }
   int n=stack.top();
   stack.pop();
   insert(stack,num);
   stack.push(n);
}

void SortedStack :: sort()
{
   //Your code here
//   stack<int> s=ss->s;
//   int n=s.size();
   if(s.empty()) {
           return ;
       }
   
    int num = s.top();
    s.pop();
   
    
    sort();
   insert(s, num);
}
