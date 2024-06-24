#include <bits/stdc++.h>
using namespace std;
int countWays(int sr, int sc, int er, int ec)
{
    if (sr > er || sc > ec)
        return 0;
    if (sc == ec && sr == ec)
        return 1;
    int rightWay = countWays(sr, sc + 1, er, ec);
    int downWay = countWays(sr + 1, sc, er, ec);
    int totalWays = rightWay + downWay;
    return totalWays;
}
void printWays(int sr, int sc, int er, int ec, string str)
{
    if (sc > ec || sr > er)
        return;
    if (sr == er && sc == ec)
    {
        cout << str << endl;
        return;
    }
    printWays(sr, sc + 1, er, ec, str + "R");
    printWays(sr + 1, sc, er, ec, str + "D");
}
int main()
{
    int rows = 3;
    int cols = 3;
    cout << countWays(1, 1, rows, cols) << endl;
    printWays(1, 1, rows, cols, "");
    return 0;
}