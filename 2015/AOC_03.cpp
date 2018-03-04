#include <iostream>
#include <cstdlib>

#include <unordered_set>

//#include "CommonTools.h"
using namespace std;



void increment(int& loc, char c)
{
  if (c == '>' )
    loc+=1;
  if (c == '<' )
    loc-=1;
  if (c == '^' )
    loc+=1000000;
  if (c == 'v' )
    loc-=1000000;
}


int main()
{

  string input;
  getline(cin, input);

  unordered_set<int> HousesVisited;
  HousesVisited.insert(0);

  int Location1 = 0;
  int Location2 = 0;


  const int InputSize = input.size();
  for(int count = 0; count < InputSize; count++)
  {
    if (count %2 == 0)
    {
      increment(Location1, input[count]);
      HousesVisited.insert(Location1);
    }
    else
    {
        increment(Location2, input[count]);
        HousesVisited.insert(Location2);
    }

  }

  cout << HousesVisited.size() << endl;

  return EXIT_SUCCESS;
}
