//getExecutionTime (microseconds)
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long fib(int n){
    if(n<=2) return 1;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    auto start = high_resolution_clock::now();
    cout<<fib(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"\ntime spent: "<<duration.count()<<" milliseconds";
}
