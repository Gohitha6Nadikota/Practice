/*
Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays.
Each element in the result must appear as many times as it appears in both arrays.
*/

// Approach 1:

vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans;
    vector<int> visited(nums2.size(), 0);

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {

            if (nums1[i] == nums2[j] && visited[j] == 0) {
                ans.push_back(nums2[j]);
                
                visited[j] = 1;
                
                break;
            } 
            else if (nums2[j] > nums1[i])
                break; 
        }
    }
    return ans;
}

// Approach 2:

vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        } 
        else if (nums1[i] < nums2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }
    return ans;
}