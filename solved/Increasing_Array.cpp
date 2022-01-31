#include<iostream>
#include<vector>
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
    long long n;
    cin>>n;
    long long delta=0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        if(i==0) continue;
        if(arr[i-1]>arr[i]){
            long long diff=arr[i-1]-arr[i];
            arr[i]+=diff;
            delta+=diff;
        }
    }

    cout<<delta;
}