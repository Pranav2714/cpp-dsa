#include <bits/stdc++.h>
using namespace std;
int findLargestPoint(vector<int> &a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : a)
    {
        pq.push(i);
    }
    while (k--)
    {
        int l1 = pq.top();
        pq.pop();
        int l2 = pq.top();
        pq.pop();
        int prod = l1 * l2;
        pq.push(prod);
    }

    while (pq.size() > 1)
    {
        pq.pop();
    }
    return pq.top();
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findLargestPoint(a, k);
    return 0;
}