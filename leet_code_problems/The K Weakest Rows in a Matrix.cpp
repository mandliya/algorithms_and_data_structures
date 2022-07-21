// https : // leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        vector<int> ans;           // create a vector to store final k indices
        vector<pair<int, int>> vp; // create vector of pair(int, int), where first int will be cnt and second will be the index.

        for (int i = 0; i < mat.size(); i++) // mat.size() is nothing but number of rows.
        {
            int cnt = 0;

            for (int j = 0; j < mat[0].size(); j++) // mat[0].size() is number of columns. this inner for loop is iterating over particular row.
            {
                if (mat[i][j] == 1) // if soldier is present then we'll increment cnt.
                {
                    cnt++;
                }
            } // when iterating over particular row is over then will have cnt (total soldiers) present in that row.

            vp.push_back(make_pair(cnt, i)); // we will push a pair of number of soldiers(cnt) found in particular row and that row's number(i).

        } //   this inner loop will continue for all rows and every time it ends the cnt is reset to zero as you can see because of outer loop.

        sort(vp.begin(), vp.end()); // sort the vector so that we'll get a vector starting from weakest row.

        for (int i = 0; i < k; i++) // loop till first k weakest rows.
        {
            ans.push_back(vp[i].second); // push indices of first k weakest rows in our ans vector. remember we have stored the indices at "second" position in a pair.
        }

        return ans;
    }
};