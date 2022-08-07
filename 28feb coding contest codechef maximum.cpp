#include<iostream>
#include<cmath>
int find_max(int);
using namespace std;
int main()
{
	int t,i,n;
	
	cin>>t;
	int m[t];
	for(i=0;i<t;i++)
	{
		cin>>n;
		m[i]=find_max(n);
	}
	for(i=0;i<t;i++)
	cout<<m[i]<<endl;
	return 0;
}
int find_max(int n1)
{
    int j,k,fun,max=0;
    int a[n1];
		for(j=0;j<n1;j++)
		cin>>a[j];
		
		for(k=0;k<n1-1;k++)
		{
			for(j=k+1;j<n1;j++)
			{
				fun=a[k]*a[j] + abs(a[k]-a[j]);
				if(fun>max)
				max=fun;
			}
		}
		return max;
}
