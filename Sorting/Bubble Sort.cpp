/*
Given an array of integers called nums,
sort the array in non-decreasing order using the bubble sort algorithm and 
return the sorted array.
*/

class Solution 
{
    public:
        vector<int> bubbleSort(vector<int>& nums)
        {
            int n=nums.size();
    
            for(int i=0;i<n-1;i++)
            {
                for(int j=1;j<n-i;j++)
                {
                    if(nums[j]<nums[j-1])
                    swap(nums[j],nums[j-1]);
                }
            }
            return nums;
        }
};
    