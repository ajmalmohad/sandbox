#include<iostream>
#include<vector>
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
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    vector<int> b(n);
    int flag=1;
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int j = 0; j < n; j++) cin>>b[j];
    for (int k = 0; k < n; k++) {
        if( b[k] == a[k]+x || b[k] == a[k]+y) continue;
        else { flag = 0; break; }
    }
    if(flag==0) cout<<"No"<<'\n';
    else cout<<"Yes"<<'\n';
}