#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "enter the number" << endl;
    int n;
    int bit;
    cin >> bit;
    cin >> n;
    cout << (n & (1 << (bit - 1))) << endl;
    return 0;
}