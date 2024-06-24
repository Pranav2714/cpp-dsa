#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 20;
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n % i)
            {
                cout << i << " ";
            }
            else
            {
                cout << i << " ";
                v.push_back(n / i);
            }
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    return 0;
}