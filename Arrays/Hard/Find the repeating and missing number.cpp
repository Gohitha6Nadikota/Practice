/*
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array,
except for A, 
which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.
*/

// Approach 1:

vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
    int n = nums.size(); 

    int xr = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ nums[i]; 
        
        xr = xr ^ (i + 1);  
    }

    int number = (xr & ~(xr - 1));

    int zero = 0; 
    int one = 0;  

    for (int i = 0; i < n; i++) {
        
        if ((nums[i] & number) != 0) {
            one = one ^ nums[i];
            
        } else {
            zero = zero ^ nums[i]; 
        }
    }

    for (int i = 1; i <= n; i++) {
        
        if ((i & number) != 0) {
            
            one = one ^ i; 
            
        } else {
            zero = zero ^ i; 
        }
    }
    int cnt = 0; 

    for (int i = 0; i < n; i++) {
        if (nums[i] == zero) {
            cnt++;
        }
    }

    if (cnt == 2) {
        return {zero, one}; 
    }
    
    return {one, zero}; 
}

// Approach 2:

vector<int> findMissingRepeatingNumbers(vector<int> nums) {

    int n=nums.size();

    long long sum=0, square=0;
    long long Asum=( (long long)n*(n+1))/2,Asquare=( (long long)n*(n+1)*(2*n+1))/6;

    for(auto x: nums)
    {
        sum+=x;
        square+=1LL*x*x;
    }

    int diff1=sum-Asum,diff2=square-Asquare;

    diff2=diff2/diff1;

    long long x=(diff1+diff2)/2,y=x-diff1;
    return {(int)x,(int)y};
}