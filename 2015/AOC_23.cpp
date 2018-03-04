#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"


using namespace std;

int main()
{


  vector<vector<string>> Instructions;

  for(string line; getline(cin, line);)
  {

    vector<string> Inst = SplitString<string>(line);

    if ( Inst[0] == "jie" or Inst[0] == "jio" )
      Inst[1].erase(1,1);

    Instructions.push_back(Inst);

  }

  map<string, int> Registers{{"a",0}, {"b", 0}};


  for( uint I = 0; I < Instructions.size(); I++)
  {
    vector<string>& Inst = Instructions[I];

    if ( Inst[0] == "hlf" )
      Registers[Inst[1]] /= 2;

    else if ( Inst[0] == "tpl" )
      Registers[Inst[1]] *= 3;

    else if ( Inst[0] == "inc" )
      Registers[Inst[1]] += 1;

    else if ( Inst[0] == "jmp" )
      I += stoi(Inst[1]) -1;

    else if ( Inst[0] == "jie" )
    {
      if ( Registers[Inst[1]] %2 == 0 )
        I += stoi(Inst[2]) -1;
    }

    else if ( Inst[0] == "jio" )
    {
      if ( Registers[Inst[1]] == 1 )
        I += stoi(Inst[2]) -1;
    }

  }

  cout << Registers << endl;





  return EXIT_SUCCESS;
}
