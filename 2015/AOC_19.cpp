#include <iostream>
#include <cstdlib>

#include "CommonTools.h"

#include <algorithm>


using namespace std;

vector<pair<string, string>> conversions;

uint ReduceMolecule(string Molecule, int depth = 0)
{

  if ( Molecule == "e" ) return depth;

  for( auto& C : conversions)
  {

      string before = C.first;
      string after  = C.second;

      for(int loc = Molecule.find(after);
              loc < Molecule.size();
              loc = Molecule.find(after, loc+1))
      {

          string NewMolecule = Molecule;
          NewMolecule.replace(loc, after.size(), before );

          uint nCall = ReduceMolecule(NewMolecule, depth + 1);

          if ( nCall > 0 ) return nCall;
      }


  }

  return 0;

}



int main()
{

  string Molecule;

  for(string line; getline(cin,line); )
  {

      if ( line.empty() ) continue;

      vector<string> Split = SplitString<string>(line);

      if (Split.size() == 3)
        conversions.push_back({Split[0], Split[2]});

      if (Split.size() == 1)
        Molecule = line;

  }

  sort(conversions.begin(), conversions.end(), [](auto& lhs, auto& rhs)
       {
          return lhs.second.size() - lhs.first.size() > rhs.second.size() - rhs.first.size();
       });


  set<string> NewMolecules;

  for( auto& C : conversions)
  {

      string before = C.first;
      string after  = C.second;

      for(int loc = Molecule.find(before);
              loc < Molecule.size();
              loc = Molecule.find(before, loc+1))
      {

          string NewMolecule = Molecule;
          NewMolecule.replace(loc, before.size(), after );

          NewMolecules.insert(NewMolecule);
      }

  }

  cout << NewMolecules.size() << endl;


  cout << ReduceMolecule(Molecule) << endl;


  return EXIT_SUCCESS;
}
