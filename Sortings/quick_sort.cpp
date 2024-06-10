#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int quick_algo(vector<int> &inp,int l,int r){
    int partition_val=inp[r];
    int hole=l;
    while(l<r){
        if(inp[l]<partition_val){
            swap(inp[hole++],inp[l]);
        }
        l++;
    }
    swap(inp[hole],inp[r]);
    return hole;
}

void quick_sort(vector<int> &inp,int l,int r){
    if(l>=r) return;
    int partition=quick_algo(inp,l,r);
    quick_sort(inp,l,partition-1);
    quick_sort(inp,partition+1,r);
}

int main(){
    vector<int> inp= {1,56,6,2,6,3,7,8,95};
    cout<<"input  - ";
    for(auto i : inp) cout<<i<<" ";
    quick_sort(inp,0,inp.size()-1);
    cout<<endl<<"output - ";
    for(auto i : inp) cout<<i<<" ";
    return 0;
}