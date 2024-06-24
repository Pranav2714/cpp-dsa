#include <bits/stdc++.h>
using namespace std;
void findPermutations(string &str, int i)
{
    if (i >= str.size())
    {
        cout << str << endl;
        return;
    }
    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        findPermutations(str, i + 1);
        swap(str[i], str[j]);
    }
}
int main()
{
    string str = "abc";
    findPermutations(str, 0);
    return 0;
}