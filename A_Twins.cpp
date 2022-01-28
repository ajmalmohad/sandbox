#include<bits/stdc++.h>
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
    int n;
    unordered_map<int,int> record;
    set<pair<int,int>> myset;
    int sum=0;
    int mysum=0;
    int mincoins=0;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        sum+=arr[i];
        record[arr[i]]++;
    }

    int target = sum/2;

    for (auto x : record){
        myset.insert(make_pair(x.first,x.second));
    }

    for (auto x = myset.rbegin(); x != myset.rend(); x++){
        int thistotal = x->first*x->second;
        int value = x->first;
        int count = x->second;

        if(mysum+thistotal > target){
            //Don't Add It all
            for (int i = 0; i < count; i++){
                if(mysum>target){
                    break;
                }else{
                    mysum+=value;
                    mincoins++;
                }
            }
            
        }else{
            mysum+=thistotal;
            mincoins+=count;
        }
        if(mysum>target){
            cout<<mincoins;
            return;
        }
    }
        
    
}