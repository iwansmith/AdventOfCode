#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "CommonTools.h"

using namespace std;

template<typename T>
int FindSum( T it_begin, T it_end, int Desired, int MaxDepth = -1, int Depth = 0)
{

  if ( Depth == MaxDepth )
    return 0;

  int nCombi = 0;
  for( T C = it_begin; C != it_end; C++)
  {
      if ( *C > Desired )
        continue;
      else if ( *C == Desired )
        nCombi++;
      else
        nCombi += FindSum( C+1, it_end, Desired - *C, MaxDepth, Depth+1 );

  }

  return nCombi;


}


int main()
{

  vector<int> Containers;
  cin >> Containers;


  sort(Containers.begin(), Containers.end(), greater<int>() );

  cout << Containers << endl;

  cout << FindSum(Containers.begin(), Containers.end(), 150, 4) << endl;
  return EXIT_SUCCESS;
}
