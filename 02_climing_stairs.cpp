#include <bits/stdc++.h>
using namespace std;
#define v vector

// Gives total number of ways
int climbStairs(int n, v<int> &dp)
{
    if(n<=1)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];

    int oneStepCount = climbStairs(n-1, dp);
    int twoStepCount = climbStairs(n-3, dp);

    dp[n] = oneStepCount + twoStepCount;
    return dp[n];
}

int main()
{
    

    return 0;
}