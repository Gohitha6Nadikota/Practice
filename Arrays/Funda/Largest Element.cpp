/*
Given an array of integers nums, return the value of the largest element in the array
*/

// Approach 1:

class Solution
{
    public:
        static int largestElement(std::vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
    
            int largest = nums[nums.size() - 1];
    
            return largest;
        }
};

// Approach 2:

class Solution 
{
    public:
        int largestElement(vector<int>& nums)
        {
            int mx=nums[0];
            for(auto x:nums)
            mx=max(mx,x);
            return mx;
        }
};