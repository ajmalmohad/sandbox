#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
 
int arr[] = {0,1,2,3,4,5,6,7,8,9};
 
int bsearch(int left, int right, int val){
    if(left>right) return -1;
    int mid = (left+right)/2;
    if( arr[mid] == val ) return mid;
    else if( val < arr[mid]) return bsearch(left,mid-1,val);
    else return bsearch(mid+1,right,val);
}
 
 
void solve(){
    ll digitCount,targetSum; 
    cin>>digitCount>>targetSum;
 
    if(targetSum==0) {
        if(digitCount==1) cout<<"0 0\n";
        else cout<<"-1 -1\n";
        return;
    }
 
    if(targetSum > digitCount*9){
        cout<<"-1 -1\n";
        return;
    }
    
    vector<int> minSum(digitCount,0);
    int sumMin = 0;
    int lastOne = 0;
    
 
    //Min Sum O(nlogn)
    for (auto &&x : minSum){
        int k = bsearch(0,9,targetSum-sumMin);
        if(k==-1){ x=9; sumMin+=9; }
        else{ x=arr[k]; sumMin+=arr[k]; }
        if(targetSum-sumMin == 0){ break; }
    }
    
    vector<int> maxSum;
    copy(minSum.begin(),minSum.end(),back_inserter(maxSum));
 
    int sizeMin = minSum.size();
    if(minSum[sizeMin-1]==0){
        for(auto x=minSum.rbegin(); x!=minSum.rend(); x++){
            if(*x == 0) continue;
            else{
                *x=*x-1;
                break;
            }
        }
        minSum[sizeMin-1]=1;
    }
 
    for(auto x=minSum.rbegin(); x!=minSum.rend(); x++) cout<<*x;  
    cout<<" ";
    
    std::sort(maxSum.begin(),maxSum.end(),greater<int>());
    
    for(auto x:maxSum) cout<<x;
    cout<<'\n'; 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) solve();
    return 0;
}