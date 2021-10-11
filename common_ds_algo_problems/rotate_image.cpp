class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=i;j<matrix[0].size();j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0, k=matrix[0].size()-1;j<k;j++,k--)
            {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
        
        //return matrix;
    }
};
