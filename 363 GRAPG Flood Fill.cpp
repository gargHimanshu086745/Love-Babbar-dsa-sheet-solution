class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     
        
        queue<pair<int,int>> qq;
        
        int oldc=image[sr][sc];
        qq.push({sr,sc});
        
        int m=image.size();
        int n= image[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         visited[i][j]=false;
        //     }
        // }
            visited[sr][sc]=true;
            
        image[sr][sc]=color;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!qq.empty())
        {
            auto x=qq.front();
            qq.pop();
            
            int newx=x.first;
            int newy=x.second;
            for(int i=0;i<4;i++)
            {
                int tempx=newx+dx[i];
                int tempy=newy+dy[i];
                if(tempx>=0 && tempx<m && tempy>=0 && tempy<n )
                if(image[tempx][tempy]==oldc && visited[tempx][tempy]==false)
                {
                    image[tempx][tempy]=color;
                    qq.push({tempx,tempy});
                    visited[tempx][tempy]=true;
                } 
            }
        }
        return image;
    }
};
