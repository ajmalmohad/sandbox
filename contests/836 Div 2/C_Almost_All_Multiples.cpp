#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    if(n%x!=0) cout<<-1;
    else{
        if(n==x){
            cout<<x<<" ";
            for (int i = 2; i < n; i++) cout<<i<<" ";
            cout<<1;
        }else{
            vector<int> seq;
            seq.reserve(n);
            seq.push_back(x);
            for (int i = 2; i < n; i++) {
                if(i==x) seq.push_back(n);
                else seq.push_back(i);
            }
            seq.push_back(1);

            int start = x;
            int end = x*2;
            while(end<n){
                if(n%end==0){
                    int temp = seq[start-1];
                    seq[start-1] = seq[end-1];
                    seq[end-1] = temp;
                    start = end;
                    end *= 2;
                }else{
                    end *= 2;
                }
            }

            for (int i = 0; i < n; i++) cout<<seq[i]<<" ";
        }
    }
    cout<<'\n';
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}