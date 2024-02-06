/*
 In mathematics, Pascal's triangle is a triangle-shaped array of binomial coefficients.
 Every number in the triangle is the sum of the two numbers directly above it, and the
 left and right edges just have a value of one.

 Given an integer for the number of rows in the triangle, return the first rows of
 Pascal's triangle, up to that value. It should be returned in the form of a vector
 of integer vectors, where vector[i][j] would represent the ith row and the jth number
 in that row.
 */

class PascalsTriangle {
public:
    vector<vector<int>> solution(int numRows) {
        vector<vector<int>> result(numRows);
        result[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; j++) {
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            temp.push_back(1);
            result[i] = temp;
        }
        return result;
    }
};