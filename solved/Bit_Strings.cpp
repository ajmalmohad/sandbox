#include<iostream>
#include<math.h>
using namespace std;
void solve();

int main()
{
    int t=1;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}

void solve(){
    const long long M = 1000000007;
    long long n;
    cin>>n;
    long long sum=1;
    for (int i = 0; i < n; i++) sum = (sum*2)%M;
    cout<<sum; 
}