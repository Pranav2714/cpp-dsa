#include<bits/stdc++.h>
using namespace std;
int printAltNum(int n){
    if(n==0) return 0;
    int sum=printAltNum(n-1);
    if(n%2==0){
         sum-=n;
    }
    else sum+=n;
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<printAltNum(n);
    return 0;
}