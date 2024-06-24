#include <bits/stdc++.h>
using namespace std;
int kthLargestEle(vector<int> &v, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
        {
            pq.pop(); // removing the smallest element out of k+1 elements
        }
    }
    return pq.top();
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << kthLargestEle(v, n, k) << endl;
    ;

    return 0;
}