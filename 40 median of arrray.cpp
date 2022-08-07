class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    sort(v.begin(),v.end());
		    int l=v.size();
		    if(l%2!=0)
		    return v[l/2];
		    else
		    {
		        int a=v[l/2];
		        int b=v[l/2-1];
		        return (a+b)/2;
		    }
		    
		}
};
