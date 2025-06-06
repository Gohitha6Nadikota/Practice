/*
Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array.
The array is guaranteed to have a majority element.
*/

// Approach 1: 

int majorityElement(vector<int>& nums) {
        
    int n = nums.size();

    unordered_map<int, int> mp;
    
    for (int num : nums) {
        mp[num]++;
    }
    
    for (auto& pair : mp) {
        if (pair.second > n / 2) {
            return pair.first;
        }
    }
    
    return -1;
}

// Approach 2: Boyer-Moore Voting Algorithm

int majorityElement(vector<int>& nums) {
    int n=nums.size();

        int el; int cnt=0;

        for(auto x: nums)
        {
            if(cnt==0)
            {
                cnt=1;
                el=x;
            }
            else if(x==el)
            cnt++;
            else
            cnt--;
        }

        cnt=0;
        for(auto x: nums)
        {
            if(x==el)
            cnt++;
        }

        if(cnt>(n/2))
        return el;
        else
        return -1;
}