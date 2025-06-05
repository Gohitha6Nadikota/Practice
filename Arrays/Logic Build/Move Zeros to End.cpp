/*
Given an integer array nums, move all the 0's to the end of the array.
The relative order of the other elements must remain the same.
This must be done in place, without making a copy of the array.
*/

// Approach 1:

void moveZeroes(vector<int>& nums) 
{

    int n = nums.size();

    vector<int> temp;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    int nz = temp.size();

    for (int i = 0; i < nz; i++) {
        nums[i] = temp[i];
    }

    for (int i = nz; i < n; i++) {
        nums[i] = 0;
    }

}

// Approach 2:

void moveZeroes(vector<int>& nums) 
{
    int j = -1; 
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}