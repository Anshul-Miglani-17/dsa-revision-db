#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> insertion_sort(vector<int> &inp){
    for(int i=1;i<inp.size();i++){
        int hole = inp[i];
        int j=i-1;
        while(j>=0 && inp[j]>hole){
            inp[j+1]=inp[j];
            j--;
        }
        inp[j+1]=hole;
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