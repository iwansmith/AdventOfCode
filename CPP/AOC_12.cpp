#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void PChain( vector<vector<int>>& Pipes, vector<int>& Connects0, int ID )
{

  if ( Connects0[ID] )
    return;

  Connects0[ID] = true;
  for( int i : Pipes[ID] ){
      PChain( Pipes, Connects0, i);
  }

}

int main()
{

  vector<vector<int>> Pipes;
  vector<int> Connects0;


  auto PropagateChain = [&Pipes, &Connects0](int ID)
  {
    PChain(Pipes, Connects0, ID);
  };


  for( string line; getline(cin,line) ;)
  {
      for( int loc = line.find(','); loc < line.size(); loc = line.find(','))
        line.replace(loc, 1, "");

      Pipes.push_back(vector<int>());
      Connects0.push_back(0);

      istringstream ss(line);

      int ID;
      ss >> ID;

      {string null;ss >> null;}

      int ConnectsTo;
      while ( ss >> ConnectsTo )
      {
        Pipes[ID].push_back(ConnectsTo);
        Connects0[ID] = 0;
      }
  }

  int nGroups = 0;

  for (
    auto location = Connects0.begin();
    location     != Connects0.end();
    location      = find(Connects0.begin(), Connects0.end(), 0)
  ){
    PropagateChain( location - Connects0.begin() );
    nGroups++;
  }

  cout << nGroups << endl;

  return EXIT_SUCCESS;
}
