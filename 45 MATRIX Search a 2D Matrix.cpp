class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row, col;
        
        row=matrix.size();
        col=matrix[0].size();
        
        // cout<<col;
        int target_row=-1;
        
        if(row==1 && col==1)
        {
            if(matrix[row-1][col-1]==target)
                return true;
            else
                return false;
        }
        
        
        
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]<=target && matrix[i][col-1]>=target)
            {
                if(matrix[i][0]==target || matrix[i][col-1]==target)
                {
                    return true;
                }
                target_row=i;
                break;
            }
        }
        
        if(target_row==-1)
            return false;
        
        int low=0, high=col-1;
        int mid;
        while(low<high )
        {
            mid=(low+high)/2;
            
            if(matrix[target_row][mid]==target)
                return true;
            else if(matrix[target_row][mid]>target)
                high=mid;
            else
                low=mid+1;
        }
            return false;
    }
};
