#include <bits/stdc++.h>
using namespace std;

pair<int, int> minDifference(vector<int> v1, vector<int> v2)
{
    // Complete this method
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    pair<int, int> result(v1[0], v2[0]);

    int min_deff = abs(v1[0] - v2[0]);

    for (int i = 0, j = 0; i < v1.size() - 1 && j < v2.size() - 1;)
    {
        if (min_deff > abs(v1[i + 1] - v2[j]))
        {
            i++;
            min_deff = abs(v1[i] - v2[j]);
            result.first = v1[i];
            result.second = v2[j];
        }
        else if (min_deff > abs(v1[i] - v2[j + 1]))
        {
            j++;
            min_deff = abs(v1[i] - v2[j]);
            result.first = v1[i];
            result.second = v2[j];
        }
        else if (abs(v1[i + 1] - v2[j]) < abs(v1[i] - v2[j + 1]))
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

int main()
{
    vector<int> v1 = {8, 33, 3, 555, 5};
    vector<int> v2 = {43, 5445, 1, 44, 55};
    pair<int, int> result = minDifference(v1, v2);
    cout << result.first << " " << result.second << endl;
}