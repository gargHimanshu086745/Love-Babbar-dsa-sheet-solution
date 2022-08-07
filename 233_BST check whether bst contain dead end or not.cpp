// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void store(Node *root,unordered_map<int,int> &map1,unordered_map<int,int> &map2)
{
    if(!root)
    return ;
    store(root->left,map1,map2);
    map1[root->data]++;
    if(root->left==NULL && root->right==NULL)
    map2[root->data]++;
    store(root->right,map1,map2);
}
void solve(bool &dead,unordered_map<int,int> map1,unordered_map<int,int> map2)
{
    unordered_map<int,int>::iterator it;
    it=map2.begin();
    while(it!=map2.end())
    {
        int low=it->first-1;
        int high=it->first+1;
        
        auto x=map1.find(low);
        if(x!=map1.end() ||low==0)
        {
            x=map1.find(high);
            if(x!=map1.end())
            {
               dead=1;
                break; 
            }
            
        }
        it++;
    }
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool dead=0;
    unordered_map<int,int>map1;
    unordered_map<int,int>map2;
    store(root,map1,map2);
    solve(dead,map1,map2);
    return dead;
}
