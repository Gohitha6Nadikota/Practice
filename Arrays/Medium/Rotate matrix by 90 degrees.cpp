/*
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
The rotation must be done in place, meaning the input 2D matrix must be modified directly.
*/

void rotateMatrix(vector<vector<int>>& matrix) {
        
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m/2;j++)
        {
            swap(matrix[i][j],matrix[i][m-j-1]);
        }
    }
}