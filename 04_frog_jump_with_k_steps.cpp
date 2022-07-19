#include <bits/stdc++.h>
using namespace std;
#define v vector

int jumpsRecursion(int index, v<int> &nums, int k)
{
    if (index == 0)
        return 0;

    int minEnergy = INT_MIN, energy = 0;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            energy = jumpsRecursion(index - i, nums, k) + abs(nums[index] - nums[index - i]);
            minEnergy = min(minEnergy, energy);
        }
    }

    return minEnergy;
}

int jumpsMemoization(int index, v<int> &nums, v<int> &dp, int k)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int minEnergy = INT_MIN, energy = 0;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            energy = jumpsMemoization(index - i, nums, dp,  k) + abs(nums[index] - nums[index - i]);
            minEnergy = min(minEnergy, energy);
        }
    }

    return dp[index] = minEnergy;
}

int jumpsTabulation(int index, v<int> &nums, v<int> &dp, int k)
{
    dp[0] = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int minEnergy = INT_MIN, energy = 0;
        for (int j = i; j <= k; i++)
        {
            energy = dp[i - j] + abs(nums[i] - nums[i - j]);
            minEnergy = min(minEnergy, energy);
        }

        dp[i] = minEnergy;
    }

    return dp[nums.size() - 1];
}

int frogJumpWithK(vector<int> &nums)
{
}

int main()
{

    return 0;
}