#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerEleIdx(vector<int> &a)
{
    int n = a.size();
    stack<int> st;
    st.push(0);
    vector<int> ans(n, n);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerEleIdx(vector<int> &a)
{
    int n = a.size();
    stack<int> st;
    st.push(0);
    vector<int> ans(n, -1);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> v = {5, 2, 4, 6, 3, 5};
    vector<int> next = nextSmallerEleIdx(v);
    vector<int> prev = prevSmallerEleIdx(v);
    int area = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int newArea = ((v[i]) * (next[i] - prev[i] - 1));
        area = max(area, newArea);
    }
    cout << area << " ";
    return 0;
}