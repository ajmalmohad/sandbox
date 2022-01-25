#include<iostream>
#include<vector>
#include <string>
using namespace std;


void print(std::vector<int> const &input)
{
    std::cout<<"[ ";
    for (auto const &i: input) {
        std::cout << i << " ";
    }
    std::cout<<"]\n";
}

bool palindrome(string n, int i){
    if(i>=n.size()/2) return true;
    else if(n[i] == n[n.size()-i-1]) return palindrome(n, i+1);
    else return false;
}


int bsearch(int arr[], int left, int right, int val){
    if(left>right) return -1;
    int mid = (left+right)/2;
    if( arr[mid] == val ) return mid;
    else if( val < arr[mid]) return bsearch(arr,left,mid-1,val);
    else return bsearch(arr,mid+1,right,val);
}

vector<vector<int>> solution;
void subsets(int arr[], int i, int n, vector<int> &ans){
    if(i==n){solution.push_back(ans);  return;}
    ans.push_back(arr[i]);
    subsets(arr, i+1 , n, ans);
    ans.pop_back();
    subsets(arr, i+1 , n, ans);
    return;
}

int main()
{
    // std::cout<<palindrome("madam",0)<<'\n';
    int arr[3] = {1,2,3};
    vector<int> ans;
    // int pos = bsearch(arr,0,2,3);
    // std::cout<<"Found at Position : "<<pos<<'\n';
    subsets(arr,0,3,ans);
    for (auto x : solution) print(x);        
}
