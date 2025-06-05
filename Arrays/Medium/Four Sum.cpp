/*
Given an integer array nums and an integer target.
Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

·a, b, c, d are all distinct valid indices of nums.
·nums[a] + nums[b] + nums[c] + nums[d] == target.

Notice that the solution set must not contain duplicate quadruplets.
One element can be a part of multiple quadruplets.
The output and the quadruplets can be returned in any order.
*/

// Approach 1:

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size(); 
    set<vector<int>> st; 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset; 
            for (int k = j + 1; k < n; k++) {
            
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
            
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                    sort(temp.begin(), temp.end()); 
                    st.insert(temp);
                    
                }
                
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Approach 2:

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> ans;
    
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            
            int k = j + 1;
            int l = n - 1;
            
            while (k < l) {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    
    return ans;
}