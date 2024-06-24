#include <bits/stdc++.h>
using namespace std;
long findSum(long num)
{
    long sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
void solve(long n)
{
    map<long, long> mp;
    for (long i = 1; i <= n; i++)
    {
        int sum = findSum(i);
        mp[sum]++;
    }
    long maxVal = LONG_MIN;
    for (auto it : mp)
    {
        maxVal = max(maxVal, it.second);
    }
    long possibleSum = 0;
    for (auto it : mp)
    {
        if (it.second == maxVal)
            possibleSum++;
    }
    cout << possibleSum << endl;
}

int main()
{
    long n;
    cin >> n;
    solve(n);
    return 0;
}