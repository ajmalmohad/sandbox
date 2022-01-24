#include<iostream>
using namespace std;
void solve();

int main()
{
    int t;
    cin>>t;
    int u = t;
    int flag=1;
    while(t){
        int temp = t%10;
        t/=10;
        if(temp == 4 || temp == 7) continue;
        else flag=0;
    }
    if(flag==0){
        if(u%4==0 || u%7==0 || u%44==0 || u%47==0 || u%77==0 || u%74==0) cout<<"YES";
        else cout<<"NO";
    }else{
        cout<<"YES";
    }
}
