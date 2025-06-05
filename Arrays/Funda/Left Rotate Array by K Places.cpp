/*
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.
*/

//Approach 1:

void rotateArray(vector<int>& nums, int k) 
{
    int n = nums.size(); 
    k = k % n;
    
    vector<int> temp;
    for(int i=0; i < k; i++) {
        temp.push_back(nums[i]);
    }
    
    for(int i=k; i < n; i++) {
        nums[i-k] = nums[i];
    }

    for(int i=0; i < k; i++) {
        nums[n-k+i] = temp[i];
    }
}

//Approach 2:

void reverseArray(vector<int>& nums, int start, int end) {

    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++, end--;
    }
}

void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; 
    
    reverseArray(nums, 0, k - 1);

    reverseArray(nums, k, n - 1);

    reverseArray(nums, 0, n - 1);
}