class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int i;
        int sum=0;
        unordered_map<int,bool> summap;
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0 || summap[sum]==true)
            return true;
            
            summap[sum]=true;
        }
        return false;
    }
};
