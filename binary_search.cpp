#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void binary_search(vector<int> &v,int x){
    int l=0,r=v.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid]==x){
            cout<<x<<" value found in array"<<endl;
            return;
        }
        else if(v[mid]>x){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<x<<" value is NOT found"<<endl;
}

//1,3,5,7,9,11
// 5. Avoid infinite loop
// Remember I said a bad choice of left or right mid will lead to an infinite loop? Let's tackle this down.
// Example:

// let mid = lo + ((hi - lo) / 2); // Bad! We should use right/upper mid!

// if (target < nums[mid]) {
// 	hi = mid - 1
// } else {
// 	lo = mid; 
// }
// Now, imagine when there are only 2 elements left in the boundary. If the logic fell into the else statement, since we are using the left/lower mid, it's simply not doing anything. It just keeps shrinking itself to itself, and the program got stuck.
// We have to keep in mind that, the choice of mid and our shrinking logic has to work together in a way that every time, at least 1 element is excluded.

// let mid = lo + ((hi - lo + 1) / 2); // Bad! We should use left/lower mid!

// if (target > nums[mid]) {
// 	lo = mid + 1; // mid is excluded
// } else {
// 	hi = mid; // mid is included
// }
// So when your binary search is stuck, think of the situation when there are only 2 elements left. Did the boundary shrink correctly?
void binary_search2(vector<int> &v,int x){
    int l=0,r=v.size()-1;
    while(l<r){
        int mid = l + (r-l+1)/2;
        if(v[mid]<=x){
            l = mid;
        }
        else{
            r=mid-1;
        }
    }
    if(v[l]==x) cout<<x<<" value Found"<<endl;
    else cout<<x<<" value is NOT found"<<endl;
}

int main(){
    vector<int> inp = {1,2,3,4,5,6,7,8,70,80,90};
    binary_search(inp,5);
    binary_search(inp,10);
    binary_search(inp,88);
    binary_search(inp,6);
    cout<<endl;
    binary_search2(inp,5);
    binary_search2(inp,10);
    binary_search2(inp,88);
    binary_search2(inp,6);    
}
