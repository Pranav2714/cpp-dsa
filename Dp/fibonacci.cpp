#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n, vector<int> &dp)
{ // TC-  O(N)   Sc- O(N)
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibonacci(n, dp);

    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    cout << prev << endl;
    return 0;
}