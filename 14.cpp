#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
		int mn=0,mx=0,diff;
//        Arrays.sort(arr);
        
        vector<int>v1;
        for(int i=0;i<n;i++)
        {
            v1.push_back(arr[i]);
        }
        
        sort(v1.begin(),v1.end());
        
        diff=v1.at(n-1)-v1.at(0);
        for(int i=1;i<n;i++)
        {
        	if(v1.at(i)>=k)
        	{
        		mx=max(v1.at(i-1)+k,v1.at(n-1)-k);
        		mn=min(v1.at(i)-k,v1.at(0)+k);
        		diff=min(diff,mx-mn);
        	}
        	else
        	{
        		continue;
			}
		}
        
        

        return diff;
    }
    
    int max(int a, int b)
    {
        if(a>=b)
        return a;
        else 
        return b;
    }
    int min(int a, int b)
    {
        if(a<=b)
        return a;
        else 
        return b;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>k;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
		}
		Solution ob;
		int ans=ob.getMinDiff(arr,n,k);
		cout<<ans<<endl;
	}
	return 0;
}
