/*
Given an integer r, return all the values in the rth row (1-indexed) in Pascal's Triangle in correct order.
In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
*/

vector<int> pascalTriangleII(int r) {
    vector<int>ans;
    ans.push_back(1);

    for(int i=1;i<r;i++)
    {
        ans.push_back(ans[i-1]*(r-i)/i);
    }
    return ans;
}