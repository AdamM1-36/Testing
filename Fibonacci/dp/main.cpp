//getExecutionTime (microseconds)
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long fib(int n){
    vector<long long> dp(2, 1);
    for(int i=0; i<n-1; ++i){
        dp.push_back(dp[i]+dp[i+1]);
    }
    return dp[n-1];
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
