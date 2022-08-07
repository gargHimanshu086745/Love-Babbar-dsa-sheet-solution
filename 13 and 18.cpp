#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		
		long long maxSubarraySum(int arr[], int n){
			long long max_so_far=arr[0];
			long long max_end_here=0;
			for(int i=0;i<n;i++)
			{
				max_end_here=max_end_here+arr[i];
				if(max_so_far<max_end_here)
				max_so_far=max_end_here;
				if(max_end_here<0)
				max_end_here=0;
			}
			return max_so_far;
		}
};

int main()
{
	int t,n;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		int a[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.maxSubarraySum(a,n)<<endl;
	}
}
