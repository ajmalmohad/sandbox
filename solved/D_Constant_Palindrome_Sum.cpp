#include <bits/stdc++.h>
using namespace std;

#define foz(i,n) for(int i=0;i<(n);i++) 
#define fon(i,a,b) for(int i=(a);i<(b);i++) 
#define mp make_pair
typedef unordered_map<int,int> umii; 
typedef map<int,int> mii; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 


void solve();

int main(){
    int t=0;
    cin>>t;
    while(t--) solve();
}

void solve(){
    int n,k,count=0,l,r,total;
    cin>>n>>k;

    int* arr = new int[n];
    int ptree[2*k+1] = {0};

    vpii pairs;
    umii sums;

    foz(i,n) cin>>arr[i];

    foz(i,n/2) {
        total = arr[i]+arr[n-i-1];
        l = min(arr[i],arr[n-i-1]);
        r = total - l;

        pairs.push_back(mp(l,r));
        sums[total]++;

        ptree[l+1] += 1;
        ptree[r+k+1] -= 1;
    }

    delete[] arr;
    
    fon(i,1,2*k+1) ptree[i] = ptree[i-1] + ptree[i];

    int ones = ptree[2] - sums[2];
    int twos = n/2 - sums[2] - ones;
    count = ones + 2*twos;

    fon(i,2,2*k+1){
        ones = ptree[i] - sums[i];
        twos = n/2 - sums[i] - ones;
        count = min(ones + 2*twos,count);
    }
    
    std::cout<<count<<'\n';
}