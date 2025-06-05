/*
Given an integer array nums sorted in non-decreasing order, 
remove all duplicates in-place so that each unique element appears only once. 
Return the number of unique elements in the array.

If the number of unique elements be k, then,

Change the array nums such that the first k elements of nums 
contain the unique values in the order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.

*/

// Approach 1:

int removeDuplicates(vector<int>& nums) {
        
    set<int> s;

    for (int val : nums) {
        s.insert(val);
    }
    
    int k = s.size();
    
    int j = 0;
    for (int val : s) {
        nums[j++] = val;
    }
    
    return k;
}

// Approach 2:

int removeDuplicates(vector<int>& nums) {

    if (nums.empty()) {
        return 0;
    }
    
    int i = 0;

    for (int j = 1; j < nums.size(); j++) {
    
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i+1;
}