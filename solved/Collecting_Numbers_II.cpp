#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n,m, count=0;
    cin>>n>>m;
    vector<int> elements(n+1);
    vector<int> positions(n+1);
    vector<bool> inversions(n);
    for (int i = 0; i < n; i++) {
        cin>>elements[i+1];
        positions[elements[i+1]] = i+1;
    }
    
    for (int i = 1; i < n; i++) {
        if(positions[i]>positions[i+1]){
            inversions[i] = true;
            count++;
        }else{
            inversions[i] = false;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        swap(elements[a], elements[b]);
        positions[elements[a]] = a;
        positions[elements[b]] = b;
        
        set<int> checks;
        if(elements[a]-1>=1) checks.insert(elements[a]-1);
        if(elements[a]+1<=n) checks.insert(elements[a]);
        if(elements[b]-1>=1) checks.insert(elements[b]-1);
        if(elements[b]+1<=n) checks.insert(elements[b]);

        for (auto elem: checks) {
            if(inversions[elem]) {
                count--;
                inversions[elem] = false;
            }
            if(positions[elem] > positions[elem+1]){
                count++;
                inversions[elem] = true;
            }
        }

        cout<<count+1<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}