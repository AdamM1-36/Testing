//not yet implemented: unsorted array, more than 1 value found
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> a, int l, int r, int x){
    int mid = (r-l+1)/2;
    if(a[mid]==x) return mid+1;
    else if((r == l && a[mid]!=x)||x<a[l]||x>a[r]) return -1;
    else if(a[mid]<x) return bs(a, mid+1, r, x);
    else if(a[mid]>x) return bs(a, l, mid-1, x);
    return 0;
}

int main(){
    int n, i;
    cout<<"How many elements?\n";
    cin>>n;
    cout<<"What is the number to find?\n";
    cin>>i;
    vector<int> a;
    cout<<"Array elements in ascending order: \n";
    while(n--){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans = bs(a, 0, a.size()-1, i);
    if(ans!=-1) cout<<"exists at pos: "<<ans;
    else cout<<"doesn't exist";
}
