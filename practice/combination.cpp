#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allsums;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        recur(candidates, target, 0, candidates.size(), 0,ans);
        return allsums;
    }
    
    void recur(vector<int>& candidates, int target, int i, int n, int sum, vector<int> &ans){
        if(sum>target || i>=n || candidates[i]>target) return;
        else if(sum==target){
            allsums.push_back(ans);
            return;
        }

        ans.push_back(candidates[i]);
        sum+= candidates[i];
        if(sum<=target) recur(candidates, target, i, n, sum, ans);
    
        ans.pop_back();
        sum-= candidates[i];
        if(sum<target) recur(candidates, target, i+1, n, sum, ans);
    }
};

int main(){
    Solution s = Solution();
    vector<int> candidates = {2,3,5};
    int target = 8;
    //Contains Duplicates 
    //Use a set to avoid duplicates and convert to vector
    vector<vector<int>> all = s.combinationSum(candidates,target);
    for (auto x : all){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<'\n';
    }
}