#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	// cout << "Input number is " << num << endl;	// Writing output to STDOUT

	unordered_map<int,int> mptoward[num];
	unordered_map<int,int> mpaway[num];
	mptoward.clear();
	mpaway.clear();
	int a,b;
	for(int i=0;i<num-1;i++)
	{
		
		cin>>a>>b;
		mpaway[a][b]++;
		mptoward[b][a]++;
	}

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int d,x,y;
		cin>>d>>x>>y;

		if(d==1)
		{
			bool print=true;
			queue<int> q;
			// q.clear();
			q.push(y);
			while(!q.empty())
			{
				int top=q.front();
				q.pop();
				for(auto neigh : mpaway[top])
				{
					int ng=neigh.first;	
					if(ng==x)
					{
						cout<<"YES"<<endl;
						print=false;
						// break;
					}
					else
					{
						q.push(ng);
					}
				}
			}
			if(print)
			cout<<"NO"<<endl;
		}
		else
		{
			bool print=true;
			queue<int> q;
			// q.clear();
			q.push(y);
			while(!q.empty())
			{
				int top=q.front();
				q.pop();
				for(auto neigh:mptoward[top])
				{
					int ng=neigh.first;	
					if(ng==x)
					{
						cout<<"YES"<<endl;
						print=false;
						// break;
					}
					else
					{
						q.push(ng);
					}
				}
			}
			if(print)
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
