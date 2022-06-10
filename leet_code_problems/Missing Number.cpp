// https : // leetcode.com/problems/missing-number/

int missingNumber(int *nums, int numsSize)
{

    int total = (numsSize * (numsSize + 1)) / 2;
    int acc = 0;

    for (int i = 0; i < numsSize; i++)
    {
        acc += nums[i];
    }

    return total - acc;
}