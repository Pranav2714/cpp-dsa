#include<bits/stdc++.h>
using namespace std;
int longestOnes(string str,int k){
    int st=0,end=0;
    int maxlength=0;
    int zeroesCount =0;
    for(;end<str.size();end++){
        if(str[end]=='0') {
            zeroesCount++;
        }
        while(zeroesCount>k){
         if(str[st]==0) zeroesCount--;
         st++;
        } 
        
    }
    maxlength=max(maxlength,st-end+1);
    return maxlength;
}
int main(){
    string str;
    int k;
    cout<<"enter binary string"<<endl;
    cin>>str;
    cout<<"enter k";
    cin>>k;
    cout<<longestOnes(str,k);
    return 0;
}