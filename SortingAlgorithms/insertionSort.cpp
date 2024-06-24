#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}
void insertionSort2(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int curr = v[i];
        int j = i - 1;
        while (j >= 0 && curr < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = curr;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // insertionSort(v);
    insertionSort2(v);
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}
