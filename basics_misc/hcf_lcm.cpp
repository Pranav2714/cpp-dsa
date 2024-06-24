#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}
int lcm(int x, int y)
{
    return (x * y / gcd(x, y));
}
int main()
{
    int x = 3, y = 6;
    cout << lcm(x, y) << endl;
    return 0;
}