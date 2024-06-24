#include <bits/stdc++.h>
using namespace std;
bool canWeGo(vector<vector<int>> &grid, int i, int j)

{
    int n = grid.size();
    return (i < n && j < n && i >= 0 && j >= 0) && (grid[i][j] == 1);
}

int findWays(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    if (i == n - 1 && j == n - 1)
    {
        for (int k = 0; k < n; k++)
        {
            for (int m = 0; m < n; m++)
            {
                cout << grid[k][m] << " ";
            }
            cout << endl;
        }
        cout << "-X----X-" << endl;
        return 1;
    }
    int ans = 0;
    grid[i][j] = 2;
    if (canWeGo(grid, i + 1, j))
        ans += findWays(grid, i + 1, j);
        

    if (canWeGo(grid, i - 1, j))
        ans += findWays(grid, i - 1, j);

    if (canWeGo(grid, i, j + 1))
        ans += findWays(grid, i, j + 1);

    if (canWeGo(grid, i, j - 1))
        ans += findWays(grid, i, j - 1);

    grid[i][j] = 1;
    return ans;
}
int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1}};
    cout << findWays(grid, 0, 0) << endl;
    return 0;
}