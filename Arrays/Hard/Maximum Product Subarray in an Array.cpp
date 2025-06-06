/*
Given an integer array nums. Find the subarray with the largest product,
and return the product of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

// Approach 1:

int maxProduct(vector<int>& nums) {
        
       
    int result = nums[0]; 
    
    for (int i = 0; i < nums.size(); i++) {
         int p = nums[i];

        for (int j = i + 1; j < nums.size(); j++) {
            
            result = max(result, p);
            
            p *= nums[j]; 
        }
        
        result = max(result, p); 
    }
    
    return result; 
}

// Approach 2:

int maxProduct(vector<int>& nums) {
        
    int prefix=1,suffix=1;
    int n=nums.size();
    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(!prefix)
        prefix=1;
        if(!suffix)
        suffix=1;

        prefix*=nums[i];
        suffix*=nums[n-i-1];

        ans=max(ans,max(prefix,suffix));
    }
    return ans;
}