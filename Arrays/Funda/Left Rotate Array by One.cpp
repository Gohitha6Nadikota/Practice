/*
Given an integer array nums, rotate the array to the left by one.
*/

void rotateArrayByOne(vector<int>& nums) 
{
    int temp = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        nums[i - 1] = nums[i];
    }

    nums[nums.size() - 1] = temp;
}