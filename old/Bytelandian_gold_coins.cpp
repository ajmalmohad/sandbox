#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<long long,long long>dp;
long long solve(long long n){
    if(n<=2) return dp[n] = n;
    if(dp[n]) return dp[n];
    else return dp[n] = max(n, solve(n/2)+solve(n/4)+solve(n/3));
}

int main()
{
    long long n;
    while(cin>>n){
        cout<<solve(n)<<'\n';
    }
}