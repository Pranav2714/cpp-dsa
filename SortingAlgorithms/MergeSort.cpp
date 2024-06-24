#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[l + i];
    }
    for (int i = 0; i < n1; i++)
    {
        right[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;   
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
}
void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
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
    mergeSort(v, 0, v.size() - 1);
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}