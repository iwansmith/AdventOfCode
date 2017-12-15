#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

string KnotHash( string Input, int hashsize = 256, int nRound = 64)
{

  Input += char(17);
  Input += char(31);
  Input += char(73);
  Input += char(47);
  Input += char(23);

  vector<int> hash(hashsize);
  iota(hash.begin(), hash.end(), 0);



  int SkipSize = 0;
  auto currentPosition = hash.begin();


  for( int round = 0; round< nRound; round++)
  {
    for (int length :Input )
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
    densehash << bitset<8>(dhash);
    //densehash << hex << dhash;
  }

  return densehash.str();

}

int SortNeighbours(vector<string>& Data , int X, int Y)
{

  if ( Data[X][Y] == '0' )
    return 0;

  Data[X][Y] = '0';

  if ( X > 0 )
    SortNeighbours(Data, X-1, Y);

  if ( X < 127 )
    SortNeighbours(Data, X+1, Y);

  if ( Y > 0 )
    SortNeighbours(Data, X, Y-1);

  if ( Y < 127 )
    SortNeighbours(Data, X, Y+1);

  return 1;
}



int main()
{


  vector<string> Data;

  string Hash_Input = "vbqugkhl-";

  int TotalUsed = 0;

  for ( int row = 0; row < 128; row ++)
  {

      string KHash = KnotHash(Hash_Input + to_string(row) ) ;
      TotalUsed +=count( KHash.begin(), KHash.end(), '1');

      Data.push_back(KHash);

      cout << KHash << "  " << Hash_Input + to_string(row) << endl;
  }

  cout << TotalUsed << endl;

  int nRegion = 0;

  for( int x = 0; x < 128; x++)
    for( int y = 0; y < 128; y++)
        nRegion += SortNeighbours(Data, x, y);

  cout << nRegion << endl;

  return EXIT_SUCCESS;
}
