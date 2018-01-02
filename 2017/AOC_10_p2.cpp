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
  const int nRound = 64;

  vector<int> hash(hashsize);
  iota(hash.begin(), hash.end(), 0);

  string instructions = "88,88,211,106,141,1,78,254,2,111,77,255,90,0,54,205";
  instructions += char(17);
  instructions += char(31);
  instructions += char(73);
  instructions += char(47);
  instructions += char(23);


  int SkipSize = 0;
  auto currentPosition = hash.begin();


  for( int round = 0; round< nRound; round++)
  {
    for (int length :instructions )
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
  }

  std::stringstream densehash;
  for( int i1 = 0; i1 < hashsize; )
  {
    int dhash = 0;
    for( int i2 = 0; i2 < 16; i1++,i2++)
      dhash ^= hash[i1];
    densehash << hex << dhash;
  }

  cout << densehash.str() << endl;

  return EXIT_SUCCESS;
}
