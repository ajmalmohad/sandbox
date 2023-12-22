#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int>& arr, int target){
    int start = 0, end = arr.size()-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid]==target) return mid+1;
        else if(target < arr[mid]) end=mid-1;
        else start=mid+1;
    }

    if(arr[start]>target) return start+1;
    if(arr[end+1]>target) return end+2;
}

void solve(){
    long long n,q;
    cin>>n>>q;
    vector<int> candies(n);
    for (int i = 0; i < n; i++) cin>>candies[i];
    sort(candies.begin(), candies.end(), greater<int>());
    for (int i = 1; i < n; i++) candies[i]=candies[i]+candies[i-1];
    
    int maxm = candies[candies.size()-1];
    int query;
    for (int i = 0; i < q; i++){
        cin>>query;
        if(query>maxm || query<0) cout<<"-1\n";
        else cout<<bsearch(candies, query)<<"\n";
    }
    
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}