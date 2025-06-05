/*
Given an integer array nums, find the subarray with the largest sum and 
return the sum of the elements present in that subarray.
*/

// Approach 1:

int maxSubArray(vector<int>& nums) {
        
    int maxi = INT_MIN; 

    for (int i = 0; i < nums.size(); i++) {
        
        int sum = 0; 
        
        for (int j = i; j < nums.size(); j++) {
            
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// Approach 2: 

int maxSubArray(vector<int>& nums) {
    long long ans=INT_MIN;
    long long sum=0;

    for(auto x: nums)
    {
        sum+=x;

        if(sum>ans)
        ans=sum;

        if(sum<0)
        sum=0;
    }
    return ans;
}