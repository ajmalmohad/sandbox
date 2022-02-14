#include <iostream>
#include <string>

using namespace std;

string GetRuler(const string& kingdom) {
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  char lastone = kingdom[kingdom.size()-1];
  char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
  if(lastone == 'Y' || lastone == 'y'){
      ruler = "nobody";
  }else{
      int flag = 0;
      for (int i = 0; i < 10; i++){
          if(lastone == vowels[i]){
              flag = 1;
              break;
          }
      }
      if(flag){
          ruler = "Alice";
      }else{
          ruler = "Bob";
      }
  }
  return ruler;
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}
