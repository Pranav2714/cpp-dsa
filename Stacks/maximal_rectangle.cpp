#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerEleIdx(vector<int> &a)
{
    int n = a.size();
    stack<int> st;
    vector<int> ans(n, -1);
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
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
vector<int> nextSmallerEleIdx(vector<int> &a)
{
    int n = a.size();
    stack<int> st;
    vector<int> ans(n, n);
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int findMaxArea(vector<int> &height)
{
    int n = height.size();
    vector<int> pse = prevSmallerEleIdx(height);
    vector<int> nse = nextSmallerEleIdx(height);
    int maxArea = 0;
    vector<int> width(n);
    for (int i = 0; i < n; i++)
    {
        width[i] = nse[i] - pse[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        int area = width[i] * height[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    vector<int> height(m);
    int maxArea = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            height[col] = (matrix[row][col] == '1') ? height[col] + 1 : 0;
        }
        maxArea = max(maxArea, findMaxArea(height));
    }
    return maxArea;
}
int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(matrix);

    return 0;
}