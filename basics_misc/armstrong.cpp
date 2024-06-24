#include<bits/stdc++.h>
using namespace std;
int pow(int p,int q){
    if(q==0) return 1;
    if(q%2==0){
        int res= pow(p,q/2);
        return res*res;
    }
    else{
        int res = pow(p,q/2);
        return p*res*res;
    }
}
int armst(int n,int d){
    if(n==0) return 0;
    return pow(n%10,d)+armst(n/10,d);
}
int main(){
    int n;
    cin>>n;
    int temp=n;
    int no_of_digits=0;
    while(temp>0){
        temp/=10;
        no_of_digits++;
    }
    int res=armst(n,no_of_digits);
    if(res==n) cout<<"Its is an Armstrong number";
    else cout<<"not an armstrong number";
 return 0;
}