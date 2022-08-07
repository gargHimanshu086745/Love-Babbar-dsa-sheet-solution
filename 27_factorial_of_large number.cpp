class Solution {
public:
    struct node
    {
        int data;
        struct node *prev;
    };
    node *head=NULL;
    vector<int>v;
    int carry=0;
    vector<int> factorial(int N){
        // code here
        
        for(int i=1;i<=N;i++)
        {
            if(i==1)
            {
                node *temp=new node;
                temp->data=i;
                temp->prev=NULL;
                head=temp;
                // v.push_back(i);
            }
            else
            {
                multiply(i);
            }
            
        }
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp=temp->prev;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    void multiply(int i)
    {
            carry=0;
            node *temp=new node;
            temp=head;
            while(temp!=NULL)
            {
                int m=temp->data*i+carry;
                if(m>9 && temp->prev==NULL)
                {
                    temp->data=m%10;
                    carry=m/10;
                    if(carry>9)
                    {
                        while(carry>0)
                        {
                            node *temp2=new node;
                            temp2->data=carry%10;
                            temp2->prev=NULL;
                            carry=carry/10;
                            temp->prev=temp2;
                            temp=temp->prev;
                        }
                        temp=NULL;
                    }
                    else
                    {
                        node *temp2=new node;
                        temp2->data=carry;
                        temp2->prev=NULL;
                        temp->prev=temp2;
                        temp=NULL;
                    }
                }
                else if(m<9 && temp->prev==NULL)
                {
                    temp->data=m%10;
                    temp=NULL;
                }
                else if(m>9 && temp->prev!=NULL)
                {
                    temp->data=m%10;
                    carry=m/10;
                    temp=temp->prev;
                }
                else
                {
                    temp->data=m%10;
                    carry=m/10;
                    temp=temp->prev;
                }
            }
    }
};
