/*
Given two integer arrays nums1 and nums2.
Both arrays are sorted in non-decreasing order.

Merge both the arrays into a single array sorted in non-decreasing order.

The final sorted array should be stored inside the array nums1 and it should be done in-place.
nums1 has a length of m + n,
where the first m elements denote the elements of nums1 and rest are 0s.
nums2 has a length of n.
*/

// Approach 1:

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int left = m - 1;  
    
    int right = 0;    

    while (left >= 0 && right < n) {
        
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--, right++;
        }
        else 
           break;
    }

    sort(nums1.begin() + 0, nums1.begin() + m);
    
    sort(nums2.begin(), nums2.end());

    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }
}

// Approach 2:

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            if (left < m && right >= m) {
                swapIfGreater(nums1, nums2, left, right - m);
            }
            else if (left >= m) {
                swapIfGreater(nums2, nums2, left - m, right - m);
            }
            else {
                swapIfGreater(nums1, nums1, left, right);
            }
            left++, right++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }

    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }
}

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
    if (arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}