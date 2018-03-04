#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"


using namespace std;

int main()
{
  const int n = 1000000;

  vector<int> sieve(n, 0);

  for( int i = 1; i < n; i++)
  {
    for(int j = 1; j * i < n and j < 50; j++)
    {
        sieve[j*i] += i*11;
    }
  }


  auto it_lower = find_if(sieve.begin(), sieve.end(), [](int i){return i > 34000000;});

  cout << it_lower - sieve.begin()<< endl;

  return EXIT_SUCCESS;
}
