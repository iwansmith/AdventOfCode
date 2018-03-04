#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "CommonTools.h"


using namespace std;

using Aunt = map<string, int>;

bool isCompatible(Aunt& Machine, Aunt& Sue)
{

  bool flag = true;

  flag *= (Machine["children:"]      == Sue["children:"]   or Sue["children:"]    == -1 );
  flag *= (Machine["cats:"]          <  Sue["cats:"]       or Sue["cats:"]        == -1 );
  flag *= (Machine["samoyeds:"]      == Sue["samoyeds:"]   or Sue["samoyeds:"]    == -1 );
  flag *= (Machine["pomeranians:"]   >  Sue["pomeranians:"]or Sue["pomeranians:"] == -1 );
  flag *= (Machine["akitas:"]        == Sue["akitas:"]     or Sue["akitas:"]      == -1 );
  flag *= (Machine["vizslas:"]       == Sue["vizslas:"]    or Sue["vizslas:"]     == -1 );
  flag *= (Machine["goldfish:"]      >  Sue["goldfish:"]   or Sue["goldfish:"]    == -1 );
  flag *= (Machine["trees:"]         <  Sue["trees:"]      or Sue["trees:"]       == -1 );
  flag *= (Machine["cars:"]          == Sue["cars:"]       or Sue["cars:"]        == -1 );
  flag *= (Machine["perfumes:"]      == Sue["perfumes:"]   or Sue["perfumes:"]    == -1 );

  return flag;




}

int main()
{

  Aunt BaseAunt;
  BaseAunt["children:"]    = -1;
  BaseAunt["cats:"]        = -1;
  BaseAunt["samoyeds:"]    = -1;
  BaseAunt["pomeranians:"] = -1;
  BaseAunt["akitas:"]      = -1;
  BaseAunt["vizslas:"]     = -1;
  BaseAunt["goldfish:"]    = -1;
  BaseAunt["trees:"]       = -1;
  BaseAunt["cars:"]        = -1;
  BaseAunt["perfumes:"]    = -1;

  Aunt MachineAunt;
  MachineAunt["children:"]    = 3;
  MachineAunt["cats:"]        = 7;
  MachineAunt["samoyeds:"]    = 2;
  MachineAunt["pomeranians:"] = 3;
  MachineAunt["akitas:"]      = 0;
  MachineAunt["vizslas:"]     = 0;
  MachineAunt["goldfish:"]    = 5;
  MachineAunt["trees:"]       = 3;
  MachineAunt["cars:"]        = 2;
  MachineAunt["perfumes:"]    = 1;

  for(string line; getline(cin, line);)
  {

      Aunt SueN = BaseAunt;
      vector<string> input = SplitString<string>(line);
      for( int i = 2; i+1 < input.size(); i+= 2)
      {
          SueN[input[i]] = stoi(input[i+1]);
      }

      if ( isCompatible(MachineAunt, SueN) )
        cout << line << endl;


  }



  return EXIT_SUCCESS;
}
