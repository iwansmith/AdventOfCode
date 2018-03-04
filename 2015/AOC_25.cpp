#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"




using namespace std;

int main()
{


  long long int val = 20151125;
  for(int R = 2; R < 2000000; R++)
  {
    for( int r = R, c = 1; r>0; --r, ++c)
      {
        val *= 252533;
        val %= 33554393;

        if ( r == 3010 && c == 3019)
        {
          cout << r << "  " << c << "  " << val << endl;

          return EXIT_SUCCESS;
        }
      }
  }










  return EXIT_SUCCESS;
}
