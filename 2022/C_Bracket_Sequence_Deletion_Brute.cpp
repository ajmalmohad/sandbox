#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    if(end-start==0) return false;
    for (int i = start; i <=(start+end+1)/2 ; i++){
        if(s[i]!=s[end-(i-start)]) return false;
    }
    return true;
}

bool isRegular(string s, int start, int end){
    if(end-start==0) return false;
    stack<char> st;
    for (int i = start; i <=end ; i++){
        if(s[i]=='(') st.push('(');
        else{
            if(st.size()==0) return false;
            else st.pop();
        }
    }
    if(st.size()==0)  return true;
    else return false;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=0, end=0;
    int count=0;
    while(end < n){
        if(isPalindrome(s, start, end) || isRegular(s, start, end)){
            end++;
            start=end;
            count++;
        }else{
            end++;
        }
    }

    cout<<count<<" "<<end-start<<"\n";
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}