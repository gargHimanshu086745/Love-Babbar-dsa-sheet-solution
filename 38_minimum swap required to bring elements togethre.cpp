#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        // Complet the function
         // Find count of elements which are
        // less than equals to k
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i] <= k)
                ++count;

        // Find unwanted elements in current
        // window of size 'count'
        int bad = 0;
        for (int i = 0; i < count; ++i)
            if (arr[i] > k)
                ++bad;

        // Initialize answer with 'bad' value of
        // current window
//        cout<<count<<bad;
        int ans = bad;
        for (int i = 0, j = count; j < n; ++i, ++j) {

            // Decrement count of previous window
            if (arr[i] > k)
                --bad;

            // Increment count of current window
            if (arr[j] > k)
                ++bad;

            // Update ans if count of 'bad'
            // is less in current window
            ans = min(ans, bad);
        }
        return ans;
    }
};

int main()
{
	Solution obj;
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cin>>k;
	int ans=obj.minSwap(arr,n,k);
	cout<<ans;
}
