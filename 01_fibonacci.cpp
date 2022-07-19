#include <bits/stdc++.h>
using namespace std;
#define v vector

// Memoization
int fib1(int n, v<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    else
    {
        dp[n] = fib1(n - 1, dp) + fib1(n - 2, dp);
        return dp[n];
    }

    // or can directly be written as
    // return  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

// Tabulation
int fib2(int n, v<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimized version of tabulation
int fib3(int n)
{
    if (n <= 1)
        return n;

    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main()
{
    int n = 5;
    v<int> dp(n + 1, -1);

    cout << fib1(n, dp);
    cout << fib2(n, dp);
    cout << fib3(n);

    return 0;
}