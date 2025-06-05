/*
Given an array of integers nums,
sort the array in non-decreasing order using the selection sort algorithm and 
return the sorted array.
*/

class Solution 
{
    public:
        vector<int> selectionSort(vector<int>& nums) 
        {
            int n=nums.size();
    
            for(int i=0;i<n;i++)
            {
                int minIndex=i;
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]<nums[minIndex])
                    minIndex=j;
                }
                if(i!=minIndex)
                swap(nums[i],nums[minIndex]);
            }
    
            return nums;
        }
};
    