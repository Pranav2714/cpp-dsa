#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int x = 20;
    int y = 10;
    int *p1 = &x;
    int *p2 = &y;
    swap(p1, p2);
    cout << x << " " << y << endl;
    int arr[2] ={5,7};
    cout<<arr<<endl;
    return 0;
}