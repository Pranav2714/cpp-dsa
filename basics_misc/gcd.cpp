#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int x, y;
    cin >> x >> y;
    int ans = gcd(x, y);
    cout << ans;
    return 0;
}