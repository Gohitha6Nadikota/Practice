/*
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.
*/

int subarraySum(vector<int> &nums, int k){
        
    int n=nums.size();

    map<int,int>mp;
    mp[0]=1;
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];

        int rem=sum-k;

        if(mp.find(rem)!=mp.end())
        cnt+=mp[rem];

        mp[sum]++;
    }
    return cnt;
}