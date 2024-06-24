#include <iostream>

using namespace std;

bool isIdeal(int n)
{
    while (n % 3 == 0)
    {
        n /= 3;
    }
    while (n % 5 == 0)
    {
        n /= 5;
    }
    return n == 1;
}

int main()
{
    int low, high;
    cin >> low >> high;

    int count = 0;
    for (int i = low; i <= high; ++i)
    {
        if (isIdeal(i))
        {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
