/*
Given an array of integers nums and an integer target.
Return the indices(0 - indexed) of two elements in nums such that they add up to target.

Each input will have exactly one solution, and the same element cannot be used twice.
Return the answer in non-decreasing order.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int>mp;

    for(int i=0;i<nums.size();i++)
    {
        int rem=target-nums[i];
        if(mp.find(rem)!=mp.end())
        {
            return {i,mp[rem]};
        }
        else
        mp[nums[i]]=i;
    }

    return {-1,-1};
}