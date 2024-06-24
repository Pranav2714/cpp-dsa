#include<bits/stdc++.h>
using namespace std;
int factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact=fact*i;
    }
   
    return fact;
}
int main(){
    cout<<"Enter the number of rows"<<endl;
    int n;
    cin>>n;
    vector<vector<int>> v (n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            int nCr=(factorial(i)/(factorial(i-k)*factorial(k)));
            cout<<nCr<<" ";
        }
        cout<<endl;
    }

    return 0;
}