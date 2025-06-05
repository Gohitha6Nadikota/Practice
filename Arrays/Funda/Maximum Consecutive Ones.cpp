/*
Given a binary array nums, return the maximum number of consecutive 1s in the array.
*/

int findMaxConsecutiveOnes(vector<int>& nums) 
{
 
    int cnt = 0;
    int maxi = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);

        } else {
            cnt = 0;
        }
    }
    return maxi;
}