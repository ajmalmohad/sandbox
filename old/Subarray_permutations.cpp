#include<iostream>
#include <vector>
using namespace std;
void solve();

int main()
{
    int t=1;
    cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);

    if(n>k && k==1) { cout<<-1<<endl; return; }

    if(n==k){
        for (int i = 1; i <= n; i++) cout<<i<<" ";  
        cout<<endl;
    }else if(n>k){
        for (int i = 1; i <= k-1; i++) cout<<i<<" ";
        for(int j = n; j>=k ; j--) cout<<j<<" ";
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}