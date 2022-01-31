#include<iostream>
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
    string s;
    cin>>s;
    int count=1;
    int maximum = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]==s[i-1]) count++;
        else count=1;
        maximum = max(count,maximum);
    }
    cout<<maximum;
}