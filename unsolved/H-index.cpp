#include <bits/stdc++.h>
using namespace std;



vector<int> GetHIndexScore(vector<int> citations_per_paper) {
  vector<int> h_index;
  
  // TODO: Calculate and return h-index score for each paper.
  return h_index;
} 

int main() {
  int tests;
  cin >> tests;
  for (int test_case = 1; test_case <= tests; test_case++) {
    // Get number of papers for this test case
    int paper_count;
    cin >> paper_count;
    // Get number of citations for each paper
    vector<int> citations(paper_count);
    for (int i = 0; i < paper_count; i++) {
      cin >> citations[i];
    }
    
    vector<int> answer = GetHIndexScore(citations);
    cout << "Case #" << test_case << ": ";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << " ";
    }
    
    cout << endl;
  }
  return 0;
}
