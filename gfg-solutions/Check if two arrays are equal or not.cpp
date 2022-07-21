// https : // practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1/?page=1&curated[]=1&sortBy=submissions#

class Solution
{
public:
    // Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N)
    {

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        return A == B;
        // code here
    }
};