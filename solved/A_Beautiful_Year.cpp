#include<bits/stdc++.h>
using namespace std;
void solve();
bool isDistinct(int n);

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
    n++;
    while(!isDistinct(n)) n++;
    cout<<n;
}

bool isDistinct(int n){
    set<int> arr;
    while(n){
        arr.insert(n%10);
        n=n/10;
    }
    if(arr.size()==4) return true;
    else return false;
}