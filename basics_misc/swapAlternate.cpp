#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int i = 0, j = 1;
    int n = 5;
    while (j < n)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i += 2;
        j += 2;
    }
    for (int ele : a)
    {
        cout << ele << " ";
    }
    return 0;
}