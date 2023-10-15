#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    vector<int> nums(7);
    for (int i = 0; i < 7; i++) cin>>nums[i];
    sort(nums.begin(), nums.end());

    int bpc = nums[nums.size()-1] - nums[0];
    int b, c;
    unordered_map<int, int> record;
    for (int i = 1; i < 6; i++){
        if(!record[nums[i]]){
            record[bpc - nums[i]] = i;
        }else{
            c = nums[i];
            b = bpc - nums[i];
        }
    }

    cout<<nums[0]<<" "<<b<<" "<<c<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}