#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    int count=0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
           count++;
            if (i != n / i)
            {
               count++;
            }
        }
        if(count>2) return false;
    }
    return count=2;
}
int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        
    }

    return 0;
}