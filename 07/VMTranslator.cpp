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
void arth_command(vector<string> commands){
  string line="";
  if(commands[0] == "add")
    line = "D=D+M";
  else if(commands[0] == "sub")
    line = "D=M-D";
  else if(commands[0] == "and")
    line = "D=D&M";
  else if(commands[0] == "or")
    line = "D=D|M";

  cout<<"@SP"<<endl;
  cout<<"M=M-1"<<endl;
  cout<<"@SP"<<endl;
  cout<<"A=M"<<endl;
  cout<<"D=M"<<endl;
  cout<<"@SP"<<endl;
  cout<<"M=M-1"<<endl;
  cout<<"@SP"<<endl;
  cout<<"A=M"<<endl;
  assert(line!="");
  cout<<line<<endl;
  cout<<"@SP"<<endl;
  cout<<"A=M"<<endl;
  cout<<"M=D"<<endl;
  cout<<"@SP"<<endl;
  cout<<"M=M+1"<<endl;
}

void comp_command(vector<string> commands){
  
}
void uni_command(vector<string> commands){
  string line = "";
  if(commands[0] == "neg")
    line = "M=-M";
  else if(commands[0]=="not")
    line = "M=!M";

  cout<<"@SP"<<endl;
  cout<<"M=M-1"<<endl;
  cout<<"A=M"<<endl;
  assert(line!="");
  cout<<line<<endl;
  cout<<"@SP"<<endl;
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

  if(commands[0] == "add" || commands[0] == "sub" || commands[0] == "ad" || commands[0] == "or"){
    arth_command(commands);
    return;
  }

  if(commands[0] == "eq" || commands[0] == "gt" || commands[0] == "lt"){
    comp_command(commands);
    return;
  }

  if(commands[0] == "not" || commands[0] == "neg"){
    uni_command(commands);
    return;
  }
}
void Translator(){
  std::string line;
  while (std::getline(std::cin, line)){
    translate(line);
  }
}
