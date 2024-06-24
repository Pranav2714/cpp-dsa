#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<string>> &grid, int row, int col)
{
    int n = grid.size();

    for (int j = 0; j < n; j++)
    {
        if (grid[row][j] == "Q") // horizontal
            return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][col] == "Q") // vertical
            return false;
    }

    // diagonal checking

    int i = row;
    int j = col;
    while (i >= 0 && j >= 0) // north west
    {
        if (grid[i][j] == "Q")
            return false;
        i--;
        j--;
    }

    i = row;
    j = col;
    while (i >= 0 && j < n) // norh east
    {
        if (grid[i][j] == "Q")
            return false;
        i--;
        j++;
    }

    i = row;
    j = col;
    while (i < n && j < n) // south east
    {
        if (grid[i][j] == "Q")
            return false;
        i++;
        j++;
    }

    i = row;
    j = col;
    while (i < n && j >= 0) // south west
    {
        if (grid[i][j] == "Q")
            return false;
        i++;
        j--;
    }
    return true;
}
/*void nQueens(vector<vector<string>> &grid,int row,vector<vector<string>>ans)
{
    int n= grid.size();
    if(row==n)
    {
        vector<string>s;
        for(int i=0; i<n; i++)
        {
            string str="";
            for(int j=0; j<n; j++)
            {
                str+=grid[i][j];
            }
            s.push_back(str);
        }
        ans.push_back(s);
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(isSafe(grid,row,j))
        {
            grid[row][j]="Q";
                         nQueens(grid,row+1,ans);
            grid[row][j]=".";
        }
    }
}*/
void nQueens(vector<vector<string>> &grid, int row)
{
    int n = grid.size();
    if (row == n)
    {
        // Print the current solution directly
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == "Q")
                    ans[i] = j;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(grid, row, j))
        {
            grid[row][j] = "Q";
            nQueens(grid, row + 1);
            grid[row][j] = ".";
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> grid(n, vector<string>(n, "."));
    vector<vector<string>> ans;

    nQueens(grid, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------" << endl;

    return 0;
}
