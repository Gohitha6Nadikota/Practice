/*
Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array.
The rightmost element is always a leader. 
The elements in the leader array must appear in the order they appear in the nums array.
*/

// Approach 1: 

vector<int> leaders(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        bool leader = true;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] >= nums[i]) {
                leader = false;
                break;
            }
        }

        if (leader) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

// Approach 2:

vector<int> leaders(vector<int>& nums) {
    vector<int> ans;
    
    if(nums.empty()) {
        return ans;
    }
    
    int max = nums[nums.size() - 1];
    ans.push_back(nums[nums.size() - 1]);
    
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] > max) {
            ans.push_back(nums[i]);
            max = nums[i];
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}