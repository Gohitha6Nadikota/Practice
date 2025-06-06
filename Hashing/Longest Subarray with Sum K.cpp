/*
Given an array nums of size n and an integer k,
find the length of the longest sub-array that sums to k.
If no such sub-array exists, return 0.
*/

int longestSubarray(vector<int> &nums, int k){
    map<int,int>mp;
    int n=nums.size();
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        int rem=sum-k;

        if(sum==k)
        ans=max(ans,i+1);

        if(mp.find(rem)!=mp.end())
        {
            ans=max(ans,i-mp[rem]);
        }
        
        if(mp.find(sum)==mp.end())
        mp[sum]=i;
    }
    return ans;
}