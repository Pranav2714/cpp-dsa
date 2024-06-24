 #include<bits/stdc++.h>
 using namespace std;
 void findSeq(int n){
    if(n==0) return;
    findSeq(n-1);
    cout<<n<<" ";
 }
 int main(){
    // int n;
    // cin>>n;
    findSeq(5);
    return 0;
 }