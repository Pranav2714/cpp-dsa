#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n==0 || n==1) return n;
    return fibo(n-2)+fibo(n-1);
}
int sumOfDigits(int n){
    if(n==0) return 0;
    else return sumOfDigits(n/10)+n%10;
}
int pow(int a,int n){
    if(n==0) return 1;
    return a*(pow(a,n-1));
}
int pow1(int a,int n){
    if(n==0) return 1;
    if(n%2==0) return pow(a,n/2)*pow(a,n/2);
    else return a*(pow(a,n/2)*pow(a,n/2));
}
int powOptimised(int p,int q){
    if(q==0) return 1;
    if(q%2==0){
        int res= powOptimised(p,q/2);
        return res*res;
    }
    else{
        int res = powOptimised(p,q/2);
        return p*res*res;
    }
}
int main(){
    cout<<"Enter the number"<<endl;
    // int n;
    // cin>>n;
    // cout<<fibo(n);
    // cout<<sumOfDigits(n);
    // cout<<pow1(2,3);
    cout<<powOptimised(3,4);
    return 0;
}