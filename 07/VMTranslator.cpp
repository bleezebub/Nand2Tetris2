#include "bits/stdc++.h"
using namespace std;
bool checkextensionvm(string fn){
  if(fn.substr(fn.find_last_of(".") + 1) == "vm") {
    return true;
  } else {
    return false;
  }
}
bool checkextensionasm(string fn){
  if(fn.substr(fn.find_last_of(".") + 1) == "asm") {
    return true;
  } else {
    return false;
  }
}
string getoutstring(string input){
  int n = input.size();
  for(int i=0;i<n;i++){
    if(input[i] == '.'){
      return input.substr(0, i) + ".asm";
    }
  }
  return "error";
}
int main(int argc, char *argv[]){
  string input = argv[1];
  string output = getoutstring(input);
  cout<<input<<endl;
  cout<<output<<endl;
  assert(checkextensionvm(input));
  assert(checkextensionasm(output));

  freopen(input.c_str(), "r", stdin);
  freopen(output.c_str(), "w", stdout);
  cout<<"hello"<<endl;
}
