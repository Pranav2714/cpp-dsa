#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> kthClosestPoints(vector<pair<int, int>> points, int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;

    for (auto &p : points)
    {
        int distance = p.first + p.second;
        pq.push(make_pair(distance, p));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<pair<int, int>> ans(k);
    while (!pq.empty())
    {
        ans[pq.size() - 1] = pq.top().second;
        pq.pop();
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> points(n);
    for (auto &pt : points)
    {
        cin >> pt.first >> pt.second;
    }
    vector<pair<int, int>> ans = kthClosestPoints(points, n, k);
    for (auto &p : ans)
    {
        cout << p.first << " --> " << p.second << endl;
    }

    return 0;
}