class Solution
{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n-2;i++){
            int st=i+1;
            int en=n-1;
            while(st<en){
                int s=A[i]+A[st]+A[en];
                if(s>X)en--;
                else if(s<X)st++;
                else if(s==X)return true;
            }
        }
        return false;
    }

};
