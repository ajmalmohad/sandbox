#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,int> record;
    for (int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        record[temp]=i;
    }

    for (int i = 1; i <= n; i++){
        cout<<record[i]<<" ";
    }
    
}