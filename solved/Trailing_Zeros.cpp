#include<iostream>
#include<cmath>
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
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 5; i <= n; i*=5){
        ans += n/i;
    }
    std::cout<<ans<<'\n';
}