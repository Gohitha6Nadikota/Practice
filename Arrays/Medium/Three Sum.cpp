/*
Given an integer array nums. Return all triplets such that:

i != j, i != k, and j != k
nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
One element can be a part of multiple triplets.
The output and the triplets can be returned in any order.
*/

// Approach 1:

vector<vector<int>> threeSum(vector<int>& nums) {

    set<vector<int>> tripletSet;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;

        for (int j = i + 1; j < n; j++) {
            int third = - (nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end()) {
    
                vector<int> temp = {nums[i], nums[j], third};
            
                sort(temp.begin(), temp.end());
                tripletSet.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());
    return ans;
}

// Approach 2:

vector<vector<int>> threeSum(vector<int>& nums) {
        
    vector<vector<int>> ans;
    
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int j = i + 1;
        int k = n - 1;
        
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    
    return ans;
}