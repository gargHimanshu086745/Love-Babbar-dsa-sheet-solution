class Solution{
	public:
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            unordered_map <int,int> m1,m2,m3;
            int i;
            for(i=0;i<n1;i++)
            {
                m1[A[i]]++;
            }
            for(i=0;i<n2;i++)
            {
                m2[B[i]]++;
            }
            for(i=0;i<n3;i++)
            {
                m3[C[i]]++;
            }
            vector<int> v;
            for(i=0;i<n1;i++)
            {
                if(m1[A[i]]>0 && m2[A[i]]>0 && m3[A[i]]>0)
                v.push_back(A[i]);
                m1[A[i]]=0;
                
            }
            return v;
        }
};
