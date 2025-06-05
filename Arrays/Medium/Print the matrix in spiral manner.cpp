/*
Given an M * N matrix, print the elements in a clockwise spiral manner. 
Return an array with the elements in the order of their appearance when printed in a spiral manner.
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size(),n=matrix[0].size();

    int top=0,right=n-1,left=0,bottom=m-1;

    vector<int>ans;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
        for(int i=right;i>=left;i--)
        {
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }

        if (left <= right) {
        for(int i=bottom; i>=top;i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
    }
    return ans;
}