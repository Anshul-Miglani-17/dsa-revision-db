#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> bubble_sort(vector<int> &inp){
    int n=inp.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(inp[j]>inp[j+1]){
                swap(inp[j],inp[j+1]);
            }
        }
    }
    return inp;
}

int main(){
    cout<<"input  - ";
    vector<int> inp={64,6,3,6,7,2,6,0},out;
    for(auto i : inp) cout<<i<<" ";
    cout<<endl;
    out = bubble_sort(inp);
    cout<<"output - ";
    for(auto i : out) cout<<i<<" ";
    cout<<endl;
    return 0;
}