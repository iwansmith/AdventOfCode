#include <iostream>
#include <cstdlib>
#include <sstream>

#include <algorithm>
#include <vector>

#include "CommonTools.h"
using namespace std;




int main()
{

  int paper = 0;
  int ribbon = 0;
  for( string line; getline(cin,line);)
  {

      vector<int> Dimensions = SplitString<int>(line, "x");
      sort(Dimensions.begin(), Dimensions.end());

      paper += 3 * Dimensions[0]*Dimensions[1];
      paper += 2 * Dimensions[0]*Dimensions[2];
      paper += 2 * Dimensions[1]*Dimensions[2];

      ribbon += 2* Dimensions[0] + 2* Dimensions[1];
      ribbon += Dimensions[0] * Dimensions[1] * Dimensions[2];
  }


  cout << paper << endl;
  cout << ribbon << endl;


  return EXIT_SUCCESS;
}
