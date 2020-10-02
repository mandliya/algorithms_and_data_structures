//Set matrix Zeroes
//Brute Force Approach
class Solution {
public:
 void setZeroes(vector<vector<int>>& matrix) {
             int row = matrix.size();
        int col = matrix[0].size();
        for(auto i = 0;i < row;i++){
             for(auto j = 0;j < col; j++){
                 if(matrix[i][j] == 0){
                    
                     for(auto k = 0; k < row; k++)
                        if(matrix[k][j] != 0)
                            matrix[k][j] = 1000000000;
                     for(auto k = 0; k < col; k++)
                         if(matrix[i][k] != 0)
                            matrix[i][k] = 1000000000;      
                }
            }
         }
        
        for(auto i = 0;i < row;i++){
            for(auto j = 0;j < col; j++){
                if(matrix[i][j] ==  1000000000)
                    matrix[i][j] = 0;
            }
        }
 }
};

//Optimized Approach(In place ,O(N*M)+O(N*M))
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
 int col0=1,row=matrix.size(),cols=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
                col0=0;
            for(int j=1;j<cols;j++)
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=cols-1;j>=1;j--)
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
        if(col0==0)
            matrix[i][0]=0;
        }
        
    }
};
