#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector <string> &str){
sort(str.begin(),str.end());
string ans="";
string s1=str[0];
string s2=str[str.size()-1];
int i=0,j=0;
while(s1[i]==s2[j]){
    ans+=s1[i];
    i++;
    j++;
    if(s1[i]!=s2[j]) break;
    
}
return ans;
}
int main(){
    cout<<"Enter number of strings"<<endl;
    int n;
    cin>>n;
    vector <string> v (n);
    cout<<"Enter strings"<<endl;
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    cout<<"Longest common prefix is :"<<longestCommonPrefix(v);
    return 0;
}