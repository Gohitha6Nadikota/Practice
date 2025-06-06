/*
Given an integer array nums. Return the number of reverse pairs in the array.

An index pair (i, j) is called a reverse pair if:
0 <= i < j < nums.length
nums[i] > 2 * nums[j].
*/

void func1(int low,int mid,int high, vector<int>& nums)
    {
        vector<int>ans;

        int i=low,j=mid+1;

        while(i<mid+1 && j<high+1)
        {
            if(nums[i]<=nums[j])
            {
                ans.push_back(nums[i++]);
            }
            else
            {
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
    }
    int func2(int low, int mid, int high, vector<int>& nums)
    {
        int cnt=0;

        int end=mid+1;

        for(int start=low;start<mid+1;start++)
        {
            while(end<=high && nums[start]>2*nums[end])
            end++;

            cnt+=(end-(mid+1));
        }

        return cnt;
    }
    int func(int low,int high, vector<int>& nums)
    {
        int ans=0;
        if(low<high)
        {
            int mid=(low+high)/2;
            ans+=func(low,mid,nums);
            ans+=func(mid+1,high,nums);
            ans+=func2(low,mid,high,nums);
            func1(low,mid,high,nums);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return func(0,n-1,nums);        
    }