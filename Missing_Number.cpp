#include<iostream>
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
    int result = 0;
    for (int i = 0; i < n-1; i++){
        int temp;
        cin>>temp;
        result ^= temp;
    }

    for (int i = 1; i <= n; i++){
        result ^= i;
    }
    
    cout<<result;
}