/*
Given an array of integers nums and an integer k,
return the total number of subarrays whose XOR equals to k.
*/

int subarraysWithXorK(vector<int> &nums, int k) {
    map<int,int>mp;
    int cnt=0;
    int Oxor=0;
    mp[Oxor]=1;

    for(auto x: nums)
    {
        Oxor^=x;

        int rem=Oxor^k;

        if(mp.find(rem)!=mp.end())
        cnt+=mp[rem];

        mp[Oxor]++;
    }
    return cnt;
}