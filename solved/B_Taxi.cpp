#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

void solve();

int main(){
    int t=1;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;

    int temp;
    int taxies = 0;
    vector<int> nums(4);
    for (int i = 0; i < n; i++){
        cin>>temp;
        if(temp == 4) taxies++;
        else nums[temp]++;
        if(nums[2]>=2) { taxies++; nums[2]-=2; } 
    }

    if(nums[2]){
        if(nums[1]>=2){
            taxies++;
            nums[1]-=2;
            nums[2]--;
        }else{
            taxies++;
            nums[1]=0;
            nums[2]--;
        }
    }

    while(nums[3]){
        if(nums[1]>=1){
            nums[1]--;
            nums[3]--;
            taxies++;
        }else{
            taxies++;
            nums[3]--;
        }
    }

    while (nums[1]){
        if(nums[1]<=4){
            taxies++;
            nums[1]=0;
        }else{
            taxies++;
            nums[1]-=4;
        }
    }
    

    cout<<taxies<<'\n';
    
}