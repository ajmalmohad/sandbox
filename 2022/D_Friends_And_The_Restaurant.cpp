#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> needed(n);
    vector<int> available(n);
    for (int i = 0; i < n; i++) cin>>needed[i];
    for (int i = 0; i < n; i++) cin>>available[i];
    
    unordered_map<int, int> remaining;
    for (int i = 0; i < n; i++) remaining[available[i]-needed[i]]++;

    vector<int> posdifference;
    vector<int> negdifference;
    int totalpositives = 0;
    for(auto twin : remaining) {
        if(twin.first<0) negdifference.push_back(twin.first);
        else {
            posdifference.push_back(twin.first);
            totalpositives += remaining[twin.first];
        }
    }
    
    sort(posdifference.begin(), posdifference.end());
    sort(negdifference.begin(), negdifference.end(),  greater<int>());

    int start = 0;
    int count= 0;
    for (int i = 0; i < negdifference.size(); i++){
        while(remaining[negdifference[i]] && start < posdifference.size()){
            if(remaining[posdifference[start]] && (negdifference[i]+posdifference[start])>=0 ){
                remaining[posdifference[start]]--;
                remaining[negdifference[i]]--;
                totalpositives -= 1;
                count++;
            }else start++;
        }
    }

    count += totalpositives/2;
    
    cout<<count<<"\n";
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}