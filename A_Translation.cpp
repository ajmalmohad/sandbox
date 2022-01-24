#include<iostream>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int flag=1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==b[n-1-i]) continue;
        else flag=0;
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
}

