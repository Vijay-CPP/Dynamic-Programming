#include <bits/stdc++.h>
using namespace std;
#define v vector

int jumpsRecursive(int index, v<int> &heights)
{
    if (index == 0)
        return 0;

    int oneStepEnergy = INT_MAX, twoStepEnergy = INT_MAX;

    oneStepEnergy = jumpsRecursive(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    if (index > 1)
        twoStepEnergy = jumpsRecursive(index - 2, heights) + abs(heights[index] - heights[index - 2]);

    return min(oneStepEnergy, twoStepEnergy);
}

int jumpsMemoization(int index, v<int> &heights, v<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int oneStepEnergy = INT_MAX, twoStepEnergy = INT_MAX;

    oneStepEnergy = jumpsMemoization(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    if (index > 1)
        twoStepEnergy = jumpsMemoization(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    dp[index] = min(oneStepEnergy, twoStepEnergy);
    return dp[index];
}

int frogJump(int n, v<int> &heights)
{
    // return jumpsRecursive(n - 1, heights);
    v<int> dp(n + 1, -1);
    // return jumpsMemoization(n-1, heights, dp);



    // Tabulation
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(fs, ss);
    }

    return dp[n-1];
}

int frogJumpSpaceOptimized(int n, v<int> &heights)
{
    // Tabulation
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{

    return 0;
}