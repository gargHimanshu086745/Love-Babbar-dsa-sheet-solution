#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int step=arr[0];
        int jump=1;
        int maxR=arr[0];
        if(n==1){
            return 0;
        }
        else if(arr[0]==0){
            return -1;
        }
        else
        {
            for(int i=1;i<n;i++){
                if(i==n-1){
                    return jump;
                }
                
                maxR=max(maxR,i+arr[i]);
                step--;
                
                if(step==0){
                    jump++;
                    step=maxR-i;
                }
                if(i>=maxR){
                    return -1;
                }
            }
        }
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
		}
		Solution ob;
		int ans=ob.minJumps(arr,n);
		cout<<ans<<endl;
	}
	return 0;
}
