/*
Given an integer array nums of size n.
Return all elements which appear more than n/3 times in the array.
The output can be returned in any order.
*/

// Approach 1: 

vector<int> majorityElementTwo(vector<int>& nums) {

    int n = nums.size(); 
    vector<int> result; 
    
    unordered_map<int, int> mpp;
    
    int mini = int(n / 3) + 1;

    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
        
        if (mpp[nums[i]] == mini) {
            result.push_back(nums[i]);
        }
        
        if (result.size() == 2) {
            break;
        }
    }
    return result;
}

// Approach 2: Boyer-Moore Voting Algorithm

vector<int> majorityElementTwo(vector<int>& nums) {
        
    int n=nums.size();

    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;

    for(auto x: nums)
    {
        if(cnt1==0 && el2!=x)
        {
            cnt1=1;
            el1=x;
        }
        else if(cnt2==0 && el1!=x)
        {
            cnt2=1;
            el2=x;
        }
        else if(el1==x)
        cnt1++;
        else if(el2==x)
        cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0,cnt2=0;
    for(auto x: nums)
    {
        if(el1==x)
        cnt1++;
        else if(el2==x)
        cnt2++;
    }

    n=(n/3);

    vector<int>ans;
    if(cnt1>n)
    ans.push_back(el1);
    if(cnt2>n && el1!=el2)
    ans.push_back(el2);

    return ans;
}