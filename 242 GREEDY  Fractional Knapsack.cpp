// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
         vector<pair<float,pair<int,int>>>vec;
        
        
        for(int i=0;i<n;i++)
        {
            float d=float(arr[i].value)/float(arr[i].weight);
            pair<int,int>p={arr[i].value,arr[i].weight};
            vec.push_back(make_pair(d,p));
        }
        sort(vec.begin(),vec.end());
        double max_value=0;
        for(int i=n-1;i>=0;i--)
        {
            if(vec[i].second.second>W)
           {
               max_value=max_value+vec[i].first*(W);
               break;
           }
           max_value=max_value+vec[i].second.first;
           W=W-vec[i].second.second;
        }
       
        return max_value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
