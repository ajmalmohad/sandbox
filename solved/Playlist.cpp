#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int n, maxm = 0, start = 0;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    set<int> visited;
    for (int i = 0; i < n; i++) {
        if(visited.find(arr[i]) == visited.end()){
            visited.insert(arr[i]);
        }else{
            maxm = max(maxm, (i - start));
            while(visited.find(arr[i]) != visited.end()){
                visited.erase(arr[start]);
                start++;
            }
            visited.insert(arr[i]);
        }
    }

    maxm = max(maxm, (n - start));
    cout<<maxm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}