/*
Given an array of integers called nums,
sort the array in non-decreasing order using the quick sort algorithm
return the sorted array.
*/

class Solution {
    public:
        int findPivot(vector<int>& nums, int low, int high)
        {
            int pivot=nums[high];
            int i = low, j=high-1;
            while(i<=j)
            {
                while(i<high && nums[i]<=pivot)
                i++;
    
                while(j>=low && nums[j]>pivot)
                j--;
    
                if(i<j)
                swap(nums[i],nums[j]);
            }
            swap(nums[high],nums[i]);
            return i;
        }
        void quickSortFunc(vector<int>& nums, int low, int high)
        {
            if(low<high)
            {
                int mid=findPivot(nums, low, high);
                quickSortFunc(nums,low,mid-1);
                quickSortFunc(nums,mid+1,high);
            }
        }
        vector<int> quickSort(vector<int>& nums) {
    
            int n=nums.size();
    
            quickSortFunc(nums,0,n-1);
    
            return nums;
        }
    };
    