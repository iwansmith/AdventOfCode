#include <iostream>
#include <cstdlib>

#include <algorithm>
#include "CommonTools.h"


using namespace std;

int main()
{
  int c = 0;
  for(string line; cin >>line;)
  {
    c+=2;


    for( int ch = 0; ch < line.size(); ch++)
    {

      if ( line[ch] == '\\' )
      {
        if ( line[ch+1] == '"' or line[ch+1] == '\\' )
          c++,ch++;
        else //( line[ch+1] == 'x' )
          c+=3,ch+=3;
      }

    }

  }

  //Part 2
  /*
  int c = 0;
  for(string line; cin >>line;)
  {
    c+=2;


    for( int ch = 0; ch < line.size(); ch++)
    {

      if ( line[ch] == '\\' or line[ch] == '"' )
        c++;
    }

  }
*/

  cout << c << endl;

  return EXIT_SUCCESS;
}
