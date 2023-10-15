#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,msum=0,isum=0;
    cin>>n;
    vector<int> me(n);
    vector<int> ilya(n);
    for(int i=0;i<n;i++) cin>>me[i];
    for(int i=0;i<n;i++) cin>>ilya[i];
    sort(me.begin(),me.end(),greater<int>());
    sort(ilya.begin(),ilya.end(),greater<int>());

    int count=0,mpointer=0,ipointer=0;
    int limit=n-(n/4);
    int temp=n;
    for(int i=0;i<limit;i++){
        isum+=ilya[i];
        ipointer=i;
        msum+=me[i];
        mpointer=i;
    }

    while(msum<isum){
        n++;
        count++;
        msum+=100;
        if(n%4==0){
            if(mpointer>=0) msum-=me[mpointer];
            mpointer--;
        }else{
            ipointer++;
            if(ipointer<temp) isum+=ilya[ipointer];
        }
    }
    
    cout<<count<<'\n';
}

int main() {
    int n;
    cin>>n;
    while(n--) solve();
}