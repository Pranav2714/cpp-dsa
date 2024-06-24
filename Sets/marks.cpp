#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    unordered_set<int> ms;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int correct = i;
            int incorrect = j;
            int unanswered = n - (i + j);
            if (unanswered >= 0)
            {
                int score = p * correct + q * incorrect;
                ms.insert(score);
            }
            else
                break;
        }
    }
    for (auto i : ms)
    {
        cout << i << " ";
    }
    return 0;
}