#include <iostream>
#include <cstdlib>

#include "CommonTools.h"

#include <map>
#include <set>

using namespace std;

map<string,int> Distances;
set<string> Towns;


uint FindRoute( set<string> TV, uint Distance, string LastTown)
{


  uint MinRoute = 0;

  for( auto& Town: Towns)
  {
      set<string> NewTV = TV;
      uint NewDistance = Distance;

      if ( NewTV.insert(Town).second == false )
        continue;
      NewDistance += Distances[LastTown+Town];


      MinRoute = max( MinRoute, FindRoute(NewTV, NewDistance, Town));

  }

  if ( MinRoute == 0)
    return Distance;

  return MinRoute;
}



int main()
{

  for(string line; getline(cin, line);)
  {

    vector<string> sl = SplitString<string>(line);

    Distances[sl[0] + sl[2]] = stoi(sl[4]);
    Distances[sl[2] + sl[0]] = stoi(sl[4]);

    Towns.insert(sl[0]);
    Towns.insert(sl[2]);

  }


  uint MinRoute = 0;
  for( auto& T:Towns)
    MinRoute = max(MinRoute, FindRoute({T}, 0, T));

  cout << MinRoute << endl;

  return EXIT_SUCCESS;
}
