#include <bits/stdc++.h>
using namespace std;
#define v vector

// Max sum of non adj element
int maxSumRecursion(int index, v<int> &nums)
{
    // This means arr[0] is taken so return arr[0]
    if (index == 0)
        return nums[index];

    if (index < 0)
        return 0;

    // If index picked then go to index-2 for non adjecency
    int pickSum = nums[index] + maxSumRecursion(index - 2, nums);

    // If not picked go to index-1
    int notPickSum = 0 + maxSumRecursion(index - 1, nums);

    return max(pickSum, notPickSum);
}

int maxSumMemoization(int index, v<int> &nums, v<int> &dp)
{
    // This means arr[0] is taken so return arr[0]
    if (index == 0)
        return nums[index];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // If index picked then go to index-2 for non adjecency
    int pickSum = nums[index] + maxSumMemoization(index - 2, nums, dp);

    // If not picked go to index-1
    int notPickSum = 0 + maxSumMemoization(index - 1, nums, dp);

    return dp[index] = max(pickSum, notPickSum);
}

// This can be optimized using threee variables
int maxSumTabulation(v<int> &nums, v<int> &dp)
{
    // We know
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int pickSum = nums[i];
        if (i > 1)
            pickSum += dp[i - 2];

        int notPickSum = 0 + dp[i - 1];

        dp[i] = max(pickSum, notPickSum);
    }
}

// Space optimized
int solve(int n, vector<int> &arr)
{
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int main()
{

    return 0;
}