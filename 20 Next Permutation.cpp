class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind1,ind2;
        
        //first replaceable element
        for(ind1 = n - 2;ind1>=0;ind1--){
            if(nums[ind1] < nums[ind1+1]) break;
        }
        
        //first element which is greater than ind1 element 
        // traversing backwards
        // executes when elements are in order like 3,2,1.
        if(ind1 < 0){
            reverse(nums.begin(),nums.end());
        }
        // otherwise
        else{
            for(ind2 = n-1;ind2>ind1;ind2--){
                if(nums[ind1]<nums[ind2]) break;
            }
            swap(nums[ind1],nums[ind2]);
            reverse(nums.begin()+ind1+1,nums.end());
        }
    }
};
