#include<iostream>
#include<cmath>
#include <numeric>
using namespace std;
typedef unsigned long long ll;

ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

void solve(){
    ll n;
    cin>>n;
    ll arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    ll gcdone = arr[0];
    for (int i = 0; i < n; i+=2){
        gcdone = gcd(gcdone,arr[i]);
    }

    ll gcdtwo = arr[1];
    for (int i = 1; i < n; i+=2){
        gcdtwo = gcd(gcdtwo,arr[i]);
    }
    
    int flag = 1;
    for (int i = 0; i < n; i+=2){
        if(arr[i]%gcdtwo == 0){
            flag=0;
            break;
        }
    }

    if(flag==1){
        cout<<gcdtwo<<'\n';
        return;
    }

    flag=1;
    for (int i = 1; i < n; i+=2){
        if(arr[i]%gcdone == 0){
            flag=0;
            break;
        }
    }

    if(flag==1){
        cout<<gcdone<<'\n';
        return;
    }

    cout<<0<<'\n';
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
