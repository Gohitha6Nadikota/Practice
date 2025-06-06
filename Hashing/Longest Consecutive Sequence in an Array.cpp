/*
Given an array nums of n integers,
return the length of the longest sequence of consecutive integers. 
The integers in this sequence can appear in any order.
*/

// Approach 1:

int longestConsecutive(vector<int>& nums) {
    int n=nums.size();

    if(n==0)
    return 0;

    sort(nums.begin(),nums.end());

    int ans=1;
    int cnt=1,prev=nums[0];

    for(int i=1;i<n;i++)
    {
        if((prev+1)==nums[i])
        cnt++;
        else if(nums[i]==prev)
        continue;
        else
        {
            cnt=1;
        }
        prev = nums[i];
        ans=max(ans,cnt);
    }
    return ans;
}

// Approach 2:

int longestConsecutive(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0; 

    int longest = 1; 
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1; 
            int x = it; 
            while (st.find(x + 1) != st.end()) {
                x = x + 1; 
                cnt = cnt + 1; 
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}