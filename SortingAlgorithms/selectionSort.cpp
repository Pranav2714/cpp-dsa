#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector <int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    { //finding minimun index in the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        { // placing the minimum element at the beginning
            swap(a[i], a[min_idx]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    for (int ele : a)
    {
        cout << ele << " ";
    }
    return 0;
}