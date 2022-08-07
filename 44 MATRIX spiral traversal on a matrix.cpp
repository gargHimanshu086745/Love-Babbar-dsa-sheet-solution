// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    
   
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>  ans;
        
        int top=0,down=r-1,left=0,right=c-1;
        int direction=0;
        
        while(top<=down && left<=right){
            if(direction==0){
               for(int i=left;i<=right;i++){
                 ans.push_back(matrix[top][i]);  // cout<<vect[top][i];
               // top++;
               }
               top++;
            }
            else if(direction==1){
                for(int i=top;i<=down;i++){
                 ans.push_back(matrix[i][right]);  //   // cout<<vect[i][right];
               
           // right--;
               }
               right--;
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);// cout<<vect[down][i];
                   // use pushback instead;
               
                    // down--;
                }
                down--;
            }
            else if(direction==3){
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                    // left=left+1;
                    // left++;
                }
                left++;
            }
            direction=(direction+1)%4;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
