#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> merge(vector<int> &lef,vector<int> &righ){
    vector<int> ans;
    int i=0,j=0;
    while(i<lef.size() && j <righ.size()){
        if(lef[i]>righ[j]){
            ans.push_back(righ[j++]);
        }
        else{
            ans.push_back(lef[i++]);
        }
    }
    while(i<lef.size()){
        ans.push_back(lef[i++]);
    }
    while(j<righ.size()){
        ans.push_back(righ[j++]);
    }
    return ans;
}

vector<int> merge_sort(vector<int> &inp,int l,int r){
    if(l==r) return {inp[l]};
    int mid = (l+r)/2;
    vector<int> lef = merge_sort(inp,l,mid);
    vector<int> righ = merge_sort(inp,mid+1,r);
    return merge(lef,righ);
}

int main(){
    cout<<"input  - ";
    vector<int> inp={64,6,3,6,7,5,6,2,9,9,33,44,55,66,-9,2,6,0},out;
    for(auto i : inp) cout<<i<<" ";
    cout<<endl;
    out = merge_sort(inp,0,inp.size()-1);
    cout<<"output - ";
    for(auto i : out) cout<<i<<" ";
    cout<<endl;
    return 0;
}