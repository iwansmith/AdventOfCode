#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{

  const int hashsize = 256;

  vector<int> hash(hashsize);
  iota(hash.begin(), hash.end(), 0);

  string instructions = "88 88 211 106 141 1 78 254 2 111 77 255 90 0 54 205";
  istringstream ss(instructions);

  int SkipSize = 0;
  auto currentPosition = hash.begin();

  int length;
  while (ss >> length )
  {

    auto newposition = currentPosition;
    auto otherposition = currentPosition + length-1;

    while ( otherposition >= hash.end())
      otherposition -= hashsize;

    for(int l=0; l < length/2; l++, newposition++, otherposition--)
    {
      while (newposition >= hash.end())
        newposition -= hashsize;

      while (otherposition < hash.begin())
        otherposition += hashsize;

      swap( *newposition, *otherposition);

    }

    currentPosition += length + SkipSize;
    SkipSize++;

  }

  cout << hash[0] * hash[1] << endl;
  return EXIT_SUCCESS;
}
