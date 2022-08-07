class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int warr=0;
        for(int i=1;i<n-1;i++)
        {
            int lmax=arr[i];
            for(int j=0;j<i;j++)
            lmax=max(lmax,arr[j]);
            
            int rmax=arr[i];
            for(int j=i+1;j<n;j++)
            rmax=max(rmax,arr[j]);
            
            warr=warr + (min(lmax,rmax)-arr[i]);
        }
        return warr;
        
    }
};
