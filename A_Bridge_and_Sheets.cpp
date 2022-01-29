#include<iostream>
#include<vector>
#include <cmath>
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
    int sheets, bridgeLength, tarpLength;
    cin>>sheets>>bridgeLength>>tarpLength;
    vector<int> pos(sheets+2);
    long long count = 0;
    long long covered = 0;

    for (int i = 0; i < sheets; i++){
        cin>>pos[i];
        if(covered<pos[i]){
            count += ceil((pos[i] - covered)/tarpLength);
            covered = pos[i] + 1;
        }else{
            covered = pos[i] + tarpLength + 1;
        } 
    }
    
    if(covered < bridgeLength-1) count += ceil((bridgeLength - covered)/tarpLength);
    cout<<count<<'\n';
}