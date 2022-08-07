// C++ program to Print all possible paths from
// top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> allPaths;

void findPathsUtil(vector<vector<int>> maze, int m,
								int n, int i, int j,
						vector<int> path, int index)
{
	
	// If we reach the bottom of maze,
	// we can only move right
	if (i == m - 1)
	{
		for(int k = j; k < n; k++)
		{
			
			//path.append(maze[i][k])
			path[index + k - j] = maze[i][k];
		}
		
		// If we hit this block, it means one
		// path is completed. Add it to paths
		// list and print
		cout << "[" << path[0] << ", ";
		for(int z = 1; z < path.size() - 1; z++)
		{
			cout << path[z] << ", ";
		}
		cout << path[path.size() - 1] << "]" << endl;
		allPaths.push_back(path);
		return;
	}
		
	// If we reach to the right most
	// corner, we can only move down
	if (j == n - 1)
	{
		for(int k = i; k < m; k++)
		{
			path[index + k - i] = maze[k][j];
		}
		
		//path.append(maze[j][k])
		// If we hit this block, it means one
		// path is completed. Add it to paths
		// list and print
		cout << "[" << path[0] << ", ";
		for(int z = 1; z < path.size() - 1; z++)
		{
			cout << path[z] << ", ";
		}
		cout << path[path.size() - 1] << "]" << endl;
		allPaths.push_back(path);
		return;
	}
	
	// Add current element to the path list
	//path.append(maze[i][j])
	path[index] = maze[i][j];
	
	// Move down in y direction and call
	// findPathsUtil recursively
	findPathsUtil(maze, m, n, i + 1,
				j, path, index + 1);
	
	// Move down in y direction and
	// call findPathsUtil recursively
	findPathsUtil(maze, m, n, i, j + 1,
						path, index + 1);
}
	
void findPaths(vector<vector<int>> maze,
					int m, int n)
{
	vector<int> path(m + n - 1, 0);
	findPathsUtil(maze, m, n, 0, 0, path, 0);
}

// Driver Code
int main()
{
	vector<vector<int>> maze{ { 1, 2, 3 },
							{ 4, 5, 6 },
							{ 7, 8, 9 } };
	findPaths(maze, 3, 3);
	
	//print(allPaths)
	return 0;
}

// This code is contributed by divyeshrabadiya07

