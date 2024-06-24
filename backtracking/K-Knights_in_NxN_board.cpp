#include <bits/stdc++.h>
using namespace std;
int maxKnights = 0;
int numK = 5;

bool isSafe(vector<vector<string>> &board, int row, int col)
{
    int n = board.size();

    int i, j;
    // 2 up 1 right
    i = row - 2;
    j = col + 1;
    if ((i >= 0 && j < n) && board[i][j] == "K")
    {
        return false;
    }

    // 2 up 1 left
    i = row - 2;
    j = col - 1;
    if ((i >= 0 && j >= 0) && board[i][j] == "K")
    {
        return false;
    }

    // 2 left 1 up
    i = row - 1;
    j = col - 2;
    if ((i >= 0 && j >= 0) && board[i][j] == "K")
    {
        return false;
    }

    // 2 left 1 down
    i = row + 1;
    j = col - 2;
    if ((i < n && j >= 0) && board[i][j] == "K")
    {
        return false;
    }

    // 2 right 1 down
    i = row + 1;
    j = col + 2;
    if ((i < n && j < n) && board[i][j] == "K")
    {
        return false;
    }

    // 2 right 1 up
    i = row - 1;
    j = col + 2;
    if ((i >= 0 && j < n) && board[i][j] == "K")
    {
        return false;
    }

    // 2 down 1 right
    i = row + 2;
    j = col + 1;
    if ((i < n && j < n) && board[i][j] == "K")
    {
        return false;
    }

    // 2 down 1 left
    i = row + 2;
    j = col - 1;
    if ((i < n && j >= 0) && board[i][j] == "K")
    {
        return false;
    }
    return true;
}
void nKnight(vector<vector<string>> board, int row, int col, int num)
{
    int n = board.size();
    if (row == n)
    {
        if (numK == num)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            cout << "----" << endl;
        }
        maxKnights = max(num, maxKnights);
        return;
    }

    else if (isSafe(board, row, col))
    {
        board[row][col] = "K";
        if (col != n - 1)
            nKnight(board, row, col + 1, num + 1);
        else
            nKnight(board, row + 1, 0, num + 1);
        board[row][col] = ".";
    }

    if (col != n - 1)
        nKnight(board, row, col + 1, num);
    else
        nKnight(board, row + 1, 0, num);
}

int main()
{
    int n = 3;
    vector<vector<string>> board(n, vector<string>(n, "."));
    nKnight(board, 0, 0, 0);
    cout << maxKnights;
    return 0;
}