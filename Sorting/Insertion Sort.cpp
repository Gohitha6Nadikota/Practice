/*
Given an array of integers called nums,
sort the array in non-decreasing order using the insertion sort algorithm and
return the sorted array.
*/

class Solution 
{
    public:
        vector<int> insertionSort(vector<int>& nums) 
        {
            int n=nums.size();
    
            for(int i=1;i<n;i++)
            {
                int j=i-1;
                int val=nums[i];
                while(j>=0 && nums[j]>val)
                {
                    nums[j+1]=nums[j];
                    j--;
                }
                nums[j+1]=val;
            }
            return nums;
        }
};
    