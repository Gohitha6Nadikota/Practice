/*
Given an array of integers, nums,
sort the array in non-decreasing order using the merge sort algorithm.
Return the sorted array.
*/

class Solution 
{
    public:
        void merge(vector<int>& nums,int low,int mid, int high)
        {
            vector<int>ans;
    
            int i=low,j=mid+1;
    
            while(i<=mid && j<=high)
            {
                if(nums[i]<nums[j])
                {
                    ans.push_back(nums[i++]);
                }
                else
                {
                    ans.push_back(nums[j++]);
                }
            }
    
            while(i<=mid)
            {
                ans.push_back(nums[i++]);
            }
    
            while(j<=high)
            {
                ans.push_back(nums[j++]);
            }
    
            for(int i=0;i<ans.size();i++)
            {
                nums[low+i]=ans[i];
            }
        }
        void mergeFunc(vector<int>& nums, int low, int high)
        {
            if(low<high)
            {
                int mid=(low+high)/2;
                mergeFunc(nums,low,mid);
                mergeFunc(nums,mid+1,high);
                merge(nums,low,mid,high);
            }
        }
        vector<int> mergeSort(vector<int>& nums) {
    
            int n = nums.size();
    
            mergeFunc(nums,0,n-1);
    
            return nums;
        }
};
    