/*
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive),
return the only number missing from the array within this range.
*/

// Approach 1:

int missingNumber(vector<int>& nums)
{
     int N = nums.size(); 

     for (int i = 0; i <= N; i++) {
         int flag = 0;
         
         for (int j = 0; j < N; j++) {
             if (nums[j] == i) {
                 flag = 1;
                 break;
             }
         }
         
         if (flag == 0) return i;
     }
     
     return -1;
 }

 // Approach 2:

 int missingNumber(vector<int>& nums)
{
    int N = nums.size(); 
    
    int freq[N+1] = {0};
    
    for (int num : nums) {
        freq[num]++;
    }
    
    for (int i = 0; i <= N; i++) {
        if (freq[i] == 0) {
            return i;
        }
    }
    
    return -1;
}

// Approach 3:

int missingNumber(vector<int>& nums)
{
    int N = nums.size();
    
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    
    int expectedSum = (N * (N + 1)) / 2;
    
    return expectedSum - sum;
}

// Approach 4:

int missingNumber(vector<int>& nums) 
{
    int N = nums.size();
    
    int xorSum = 0;
    
    for (int i = 0; i < N; i++) {
        xorSum ^= nums[i];
    }
    
    for (int i = 0; i <= N; i++) {
        xorSum ^= i;
    }
    
    return xorSum;
}