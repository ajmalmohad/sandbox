#include<iostream>
using namespace std;
void solve();

int main()
{
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

void solve(){
    long long n;
    int counter=0;
    cin>>n;
    while(n){
        int temp = n%10;
        if(temp == 4 || temp == 7) counter++;
        n/=10;
    }
    if(counter == 4 || counter == 7) cout<<"YES";
    else cout<<"NO";
}