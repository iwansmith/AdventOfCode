#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"


vector<int> minV(vector<int>& lhs, vector<int> & rhs)
{
  if ( lhs.size() != rhs.size() )
    return lhs.size() < rhs.size()? lhs : rhs;

  float sumlhs = accumulate(lhs.begin(), lhs.end(), 1.0 ,std::multiplies<float>());
  float sumrhs = accumulate(rhs.begin(), rhs.end(), 1.0, std::multiplies<float>());

  return sumlhs < sumrhs? lhs : rhs;
}

vector<int> CombinePackages(vector<int> Packages, int Desired, int maxdepth, int depth = 0)
{
  if ( Desired == 0)
    return {};

  if ( depth == maxdepth )
    return {};

  vector<int> MinVector(1000,999);

  for(uint i = 0; i < Packages.size(); i++)
  {
    vector<int> NP(Packages.begin() + i+1, Packages.end());

    if ( Desired - Packages[i] < 0 )
      continue;

    if ( Desired - Packages[i] == 0 )
      return {Packages[i] };

    vector<int> CP = CombinePackages(NP, Desired - Packages[i], maxdepth, depth+1);

    if ( not CP.empty() )
    {
      CP.push_back(Packages[i]);

      //return CP;
      MinVector = minV( MinVector, CP);
    }

  }

  return MinVector;


}



using namespace std;

int main()
{


  vector<int> Packages; cin >> Packages;

  sort(Packages.begin(), Packages.end(), greater<int>());

  int DesiredWeight = accumulate(Packages.begin(), Packages.end(), 0) / 3;


  vector<int> Smallest1 = CombinePackages(Packages, DesiredWeight, 6);

  cout << Smallest1 << endl;
  cout << accumulate(Smallest1.begin(), Smallest1.end(), (long long int)1, multiplies<long long int>()) << endl;

  return EXIT_SUCCESS;
}
