/*
Given two sorted arrays nums1 and nums2, 
return an array that contains the union of these two arrays.
The elements in the union must be in ascending order.
*/

// Approach 1:

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) 
{

     set<int> s; 
     vector<int> Union;

     for (int num : nums1) {
         s.insert(num);
     }

     for (int num : nums2) {
         s.insert(num);
     }

     for (int num : s) {
         Union.push_back(num);
     }

     return Union;
}

// Approach 2:

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> Union; 
    int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();

    while (i < n && j < m) {
          if (nums1[i] <= nums2[j]){ 

              if (Union.size() == 0 || Union.back() != nums1[i])
                  Union.push_back(nums1[i]);
                  i++;
              } 
              else{
                  if (Union.size() == 0 || Union.back() != nums2[j])
                  Union.push_back(nums2[j]);
                  j++;
              }
           }
    while (i < n){ 
        if (Union.back() != nums1[i])
            Union.push_back(nums1[i]);
        i++;
    }
    while (j < m){ 
        if (Union.back() != nums2[j])
            Union.push_back(nums2[j]);
        j++;
    }

    return Union;
}