#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"

#include <unordered_map>
#include <vector>

using namespace std;

using suint = short unsigned int;



int main()
{

  map<string, suint> Wires;
  vector<string> Commands {"AND", "OR", "LSHIFT", "RSHIFT", "NOT"};



  auto GetValue = [&Wires](string Val)->suint
      {
        auto it_numeric = find_if( Val.begin(), Val.end(), [](char c){ return c >= '0' and c <= '9'; });

        if ( it_numeric < Val.end())
          return stoi(Val);

        return Wires.at(Val);

      };

  auto IsValid = [&Wires](string Val)->bool
      {
        auto it_numeric = find_if( Val.begin(), Val.end(), [](char c){ return c >= '0' and c <= '9'; });

        if ( it_numeric < Val.end())
          return true;

        return Wires.count(Val)>0;

      };

  map<string, suint> OldWires;

  vector<string> lines;
  for(string line; getline(cin, line);)
    lines.push_back(line);

  do
  {

    OldWires = Wires;
    for(auto& line: lines)
    {

      Wires["b"] = 956;
      vector<string> Instructions = SplitString<string>(line);
      string Wire = Instructions.back();

      //Find out if there is an instruction

      auto it_Command = find_if( Instructions.begin(), Instructions.end(),
               [&Commands](string s)
               {
                 return find(Commands.begin(), Commands.end(), s) < Commands.end();
               });

      if ( it_Command < Instructions.end() )
      {
          string Command = *it_Command;
          if (Command == "NOT")
          {
            if ( IsValid(Instructions.at(1)))
              Wires[Wire] = ~ GetValue(Instructions.at(1));

          }

          else if ( IsValid(Instructions[0]) && IsValid(Instructions[2]) )
          {
            if (Command == "AND")
              Wires[Wire] = GetValue(Instructions.at(0)) & GetValue(Instructions.at(2));
            else if (Command == "OR")
              Wires[Wire] = GetValue(Instructions.at(0)) | GetValue(Instructions.at(2));
            else if (Command == "LSHIFT")
              Wires[Wire] = GetValue(Instructions.at(0)) << stoi(Instructions.at(2));
            else if (Command == "RSHIFT")
              Wires[Wire] = GetValue(Instructions.at(0)) >> stoi(Instructions.at(2));
          }
      }
      else
      {
          if ( IsValid(Instructions[0]))
            Wires[Instructions.at(2)] = GetValue(Instructions.at(0));
      }



    }
    cout << Wires << endl;
  }while(OldWires != Wires);

  cout << Wires << endl;

  return EXIT_SUCCESS;
}
