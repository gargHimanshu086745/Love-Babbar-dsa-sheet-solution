class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();

        int c = 1;

        unordered_map<int, int> go;

        bool rev = false;

        for (int i = n - 1; i >= 0; i--)
        {

            if (rev)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (board[i][j] != -1)
                        go[c] = board[i][j];

                    c++;
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != -1)
                        go[c] = board[i][j];

                    c++;
                }
            }

            rev = 1 ^ rev;
        }

        
       

        queue<int> q;

        q.push(1);

        vector<bool> vis(n * n + 1, false);
        vis[0] = true;

        int steps = 0;

        while (!q.empty())
        {
            int s = q.size();

            steps++;

            while (s--)
            {
                int cur = q.front();
                q.pop();

                for (int i = cur + 1; i <= cur + 6; i++)
                {
                    int next = i;

                    if (go.count(i))
                        next = go[i];


                    if(next>=n*n)
                        return steps;

                    if ( !vis[next]){

                        vis[next]=true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
  
};
