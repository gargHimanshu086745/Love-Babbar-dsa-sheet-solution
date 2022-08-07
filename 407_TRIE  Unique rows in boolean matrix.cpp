// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    // struct TrieNode *root = getNode();
  
    // // Construct trie
    
    // for (int i = 0; i < row; i++)
    // {
    //     insert(root, M,row,col,i);
    // }
    
    // printunique(root);
    // int diff_row=0;
    
    vector<int> temp;
    set<vector<int>> st;
    vector<vector<int>> ans;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.push_back(M[i][j]);
        }
        if(st.find(temp)==st.end())
        {
            st.insert(temp);
            ans.push_back(temp);
            
        }
        temp.clear();
    }
    // vector<vector<int>> ans(st.begin(),st.end());
    return ans;
    
}
