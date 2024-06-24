#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int base = 2;
    int digits = (int)(log(n) / log(base)) + 1;
    cout << digits;
    return 0;
}