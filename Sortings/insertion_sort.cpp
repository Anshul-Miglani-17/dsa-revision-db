#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> insertion_sort(vector<int> &inp){
    int n=inp.size();
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        int min_idx=-1;
        for(int j=i;j<n;j++){
            if(inp[j]<mini){
                mini=inp[j];
                min_idx=j;
            }
        }
        swap(inp[i],inp[min_idx]);
    }
    return inp;
}

int main(){
    cout<<"input  - ";
    vector<int> inp={64,6,3,6,7,2,6,0},out;
    for(auto i : inp) cout<<i<<" ";
    cout<<endl;
    out = insertion_sort(inp);
    cout<<"output - ";
    for(auto i : out) cout<<i<<" ";
    cout<<endl;
    return 0;
}