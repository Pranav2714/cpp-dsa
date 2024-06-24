#include<bits/stdc++.h>
using namespace std;
string removeocc(string &str,int idx,int n){
    if(idx==n) return "";
    string curr= "";
    curr+=str[idx];
    return ((str[idx]=='a' ? "" : curr) + removeocc(str,idx+1,n));
}
int main(){
    string str ="abcax";
    cout<<removeocc(str,0,str.size());
    return 0;
}