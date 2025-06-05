/*
Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.
In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
*/

vector<vector<int>> pascalTriangleIII(int n) {
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++)
    {
        vector<int>subAns;
        subAns.push_back(1);
        for(int j=1;j<i;j++)
        {
            subAns.push_back((subAns[j-1]*(i-j))/(j));
        }
        ans.push_back(subAns);
    }
    return ans;
}