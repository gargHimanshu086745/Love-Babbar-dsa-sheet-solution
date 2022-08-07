class Solution{
   public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long int mn,choc;
    if(m==1)
    return 0;
    
    mn=a[m-1]-a[0];
    
    for(long long int i=0;i<n-m+1;i++)
    {
        mn=min(mn,a[m-1+i]-a[0+i]);
    }
    choc=mn;
        
    return choc;
    }
};
