#include<bits/stdc++.h>
using namespace std;
void lexSort(char a[][60], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(strcmp(a[min_idx],a[j])>0){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(a[min_idx],a[i]);
        }
    }
}
int main(){
    char fruit[][60]={"papaya","apple","mango","watermelon","banana"};;
    int n = sizeof(fruit)/sizeof(fruit[0]);
    lexSort(fruit,n);
    for(int i=0;i<n;i++){
        cout<<fruit[i]<<" ";
    }
}