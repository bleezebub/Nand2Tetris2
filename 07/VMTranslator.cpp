#include "bits/stdc++.h"
using namespace std;
//asserts that file extensions are correct
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

//gets the file name for output file
string getoutstring(string input){
  int n = input.size();
  for(int i=0;i<n;i++){
    if(input[i] == '.'){
      return input.substr(0, i) + ".asm";
    }
  }
  return "error";
}
//parses the lines into seperate words
vector<string> getparsewords(string line){
  stringstream s(line);
  string word;
  vector<string> commands;
  while(s>>word){
    commands.push_back(word);
  }
  return commands;
}
void Translator();
int main(int argc, char *argv[]){
  string input = argv[1];
  string output = getoutstring(input);
  assert(checkextensionvm(input));
  assert(checkextensionasm(output));
  freopen(input.c_str(), "r", stdin);
  freopen(output.c_str(), "w", stdout);
  Translator();
}
/*Implements push constant*/
void push_constant(std::vector<string> commands){
    string val = commands.back();
    cout<<"@"<<val<<endl;
    cout<<"D=A"<<endl;
    cout<<"@SP"<<endl;
    cout<<"A=M"<<endl;
    cout<<"M=D"<<endl;
    cout<<"@SP"<<endl;
    cout<<"M=M+1"<<endl;
}
/*Implements add*/
void add_command(vector<string> commands){
  cout<<"@0"<<endl;
  cout<<"M=M-1"<<endl;
  cout<<"@0"<<endl;
  cout<<"A=M"<<endl;
  cout<<"D=M"<<endl;
  cout<<"@0"<<endl;
  cout<<"M=M-1"<<endl;
  cout<<"@0"<<endl;
  cout<<"A=M"<<endl;
  cout<<"D=D+M"<<endl;
  cout<<"@0"<<endl;
  cout<<"A=M"<<endl;
  cout<<"M=D"<<endl;
  cout<<"@0"<<endl;
  cout<<"M=M+1"<<endl;
}

void push_command(vector<string> commands){
  assert(commands[0] == "push");

  if(commands[1] == "constant"){
    push_constant(commands);
    return;
  }

}
void translate(string line){
  vector<string> commands = getparsewords(line);
  assert(commands.size()>0);

  if(commands[0] == "push"){
    push_command(commands);
    return;
  }

  if(commands[0] == "add"){
    add_command(commands);
    return;
  }
}
void Translator(){
  std::string line;
  while (std::getline(std::cin, line)){
    translate(line);
  }
}
