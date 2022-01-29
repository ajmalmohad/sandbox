#include<iostream>
#include<vector>
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
    cin>>n;

    if(n==1){
        cout<<n;
        return;
    }else if(n<4){
        cout<<"NO SOLUTION";
        return;
    }

    vector<int> odd;
    vector<int> even;

    for (int i = 1; i <=n; i++)
    {
        if(i%2==0) even.push_back(i);
        else odd.push_back(i);
    }

    if(n==4){
        for(auto it=even.begin(); it != even.end(); ++it){
            cout<<*it<<" ";
        }

        for(auto it=odd.begin(); it != odd.end(); ++it){
            cout<<*it<<" ";
        }
        return;
    }

    for(auto it=even.rbegin(); it != even.rend(); ++it){
        cout<<*it<<" ";
    }

    for(auto it=odd.rbegin(); it != odd.rend(); ++it){
        cout<<*it<<" ";
    }
}