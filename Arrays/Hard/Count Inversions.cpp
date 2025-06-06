/*
Given an integer array nums. Return the number of inversions in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.
*/

long long func1(int low,int mid,int high, vector<int>& nums)
   {
        vector<int>ans;

        int i=low,j=mid+1;

        long long cnt=0;

        while(i<mid+1 && j<high+1)
        {
            if(nums[i]<=nums[j])
            {
                ans.push_back(nums[i++]);
            }
            else
            {
                cnt+=(mid-i+1);
                ans.push_back(nums[j++]);
            }
        }

        while(i<mid+1)
        {
            ans.push_back(nums[i++]);
        }

        while(j<high+1)
        {
            ans.push_back(nums[j++]);
        }

        for(int i=0;i<ans.size();i++)
        {
            nums[low+i]=ans[i];
        }
        return cnt;
   }
   long long func(int low,int high, vector<int> &nums)
   {
        long long ans=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            ans+=func(low,mid,nums);
            ans+=func(mid+1,high,nums);
            ans+=func1(low,mid,high,nums);
        }
        return ans;
   }
   long long int numberOfInversions(vector<int> nums) {
        int n=nums.size();

        return func(0,n-1,nums);
    }