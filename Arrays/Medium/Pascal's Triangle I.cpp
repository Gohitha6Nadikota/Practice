/*
Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.
In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.
*/

int pascalTriangleI(int r, int c) {

    r--;
    c--;
    int a=min(r-c,c);
    long long ans=1;
    for(int i=0;i<a;i++)
    {
        ans=(ans*(r-i)/(i+1));
    }
    return ans;
}