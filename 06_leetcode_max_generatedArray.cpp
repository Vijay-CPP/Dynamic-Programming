#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + dp[(i / 2) + 1];
        }

        int maxEle = INT_MIN;
        for (auto it : dp)
        {
            maxEle = max(maxEle, it);
        }

        return maxEle;
    }
};

int getMax(int ind, vector<int> &nums, vector<int> &dp)
{

    if (dp[ind] != -1)
        return dp[ind];

    if (ind < 0)
        return 0;

    if (ind % 2 == 0)
        dp[ind] = getMax(ind / 2, nums, dp);
    else
        dp[ind] = getMax(ind / 2, nums, dp) + getMax((ind / 2) + 1, nums, dp);

    return dp[ind];
}

int getMaximumGeneratedMemoization(int n)
{
    if (n <= 1)
        return n;

    vector<int> nums(n + 1, -1);
    vector<int> dp(n + 1, -1);
    dp[0] = nums[0] = 0;
    dp[1] = nums[1] = 1;

    for (int i = 2; i <= n; ++i)
        nums[i] = getMax(i, nums, dp);

    int maxi = INT_MIN;
    for (auto it : nums)
    {
        maxi = max(maxi, it);
    }

    return maxi;
}

int main()
{

    return 0;
}