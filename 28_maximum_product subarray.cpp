class Solution{
public:

	// Function to find maximum product subarray
	
	
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long int maxprod=arr[0],minprod=arr[0];
	    if(n==1)
	    return arr[0];
	    long long int choice1,choice2;
	    long long int ans=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        choice1=minprod*arr[i];
	        choice2=maxprod*arr[i];
	        minprod=min(arr[i],min(choice1,choice2));
	        maxprod=max(arr[i],max(choice1,choice2));
	        ans=max(ans,maxprod);
	    }
	    return ans;
	}
	long long int min(long long int a,long long int b)
	{
	    if(a<b)
	    return a;
	    else
	    return b;
	}
	long long int max(long long int a,long long int b)
	{
	    if(a>b)
	    return a;
	    else
	    return b;
	}
};
