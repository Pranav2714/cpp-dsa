#include<bits/stdc++.h>
using namespace std;
void printMultiples(int n,int k){
    if(k==0) return;
    printMultiples(n,k-1);
    cout<<n*k<<" ";
}
int main (){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    cout<<"Enter k"<<endl;
    int k;
    cin>>k;
    printMultiples(n,k);
    return 0; 
}