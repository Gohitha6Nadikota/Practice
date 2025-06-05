/*
Given an array of integers nums, return the second-largest element in the array.
If the second-largest element does not exist, return -1.
*/

// Approach 1:

int secondLargestElement(vector<int>& nums) 
{
    int n = nums.size();
    
    if (n < 2) {
        return -1; 
    }
    
    sort(nums.begin(), nums.end());

    int largest = nums.back();

    int secondLargest = -1;

    for (int i = n-2; i >= 0; i--) {

        if (nums[i] != largest) {

            secondLargest = nums[i];
            break;

        }
    }

    return secondLargest ;
}

// Approach 2:

int secondLargestElement(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) {
        return -1; 

    }
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        largest = max(largest, nums[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > secondLargest && nums[i] != largest) {
            secondLargest = nums[i];
        }

    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
}

// Approach 3:

int secondLargestElement(vector<int>& nums) {
    if (nums.size() < 2) {
        return -1;
    }

    int large = INT_MIN;
    int second_large = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] > large) {
            second_large = large;
            large = nums[i];
        } 
        else if (nums[i] > second_large && nums[i] != large) {
            second_large = nums[i];
        }

    }
    return second_large == INT_MIN ?  -1 : second_large;
}