#include <bits/stdc++.h>
using namespace std;
bool isSumPossible(int a, int b, int c, int d)
{
    if (a == c && b == d)
        return true;
    else if (a > c || b > d)
        return false;
    else
    {
        if (a < c)
        {
            if (isSumPossible(a + b, b, c, d))
                return true;
        }
        if (b < d)
        {
            if (isSumPossible(a, b + a, c, d))
                return true;
        }
        return false;
    }
}
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (isSumPossible(a, b, c, d))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}