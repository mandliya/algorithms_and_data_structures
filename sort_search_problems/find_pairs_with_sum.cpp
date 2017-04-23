#include <bits/stdc++.h>


void printPairWithSum(const std::vector<int>& arr, const int sum)
{
    std::unordered_map<int, int> hashMap;
    bool found = false;
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        // We need to check if pair(arr[i], sum-arr[i]) already
        // exists in the map
        //
        if (hashMap.find(sum-arr[i]) != hashMap.end())
        {
            std::cout << "Found pair with sum: " << sum
                << " with values (" << sum-arr[i] << " ," << arr[i]
                << ") at indices (" <<  hashMap[sum-arr[i]] << " ,"
                << i << ")" << std::endl;
            found = true;
        }
        hashMap[arr[i]] = i;
    }
    if (!found) std::cout << "Pair not found\n";
}

int main()
{
    std::vector<int> arr {8, 7, 2, 5, 3, 1};
    printPairWithSum(arr, 10);
    return 0;
}