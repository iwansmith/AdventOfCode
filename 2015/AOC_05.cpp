#include <iostream>
#include <cstdlib>

#include <algorithm>

#include "CommonTools.h"


using namespace std;

int main()
{

  int nNice = 0;
  for(string line; getline(cin, line);)
  {



      bool nice = false;

      for( auto it = line.begin(); it < line.end()-3; it++)
      {
          string substr(it, it+2);
          if ( line.find(substr, it-line.begin()+2) < line.size() ) nice = true;

      }

      if ( not nice )
        continue;

      nice = false;

      for( auto it = line.begin()+2; it < line.end(); it++)
        if ( *it == *(it-2) ) nice = true;

      if ( not nice )
        continue;



      nNice++;

  }

    cout << nNice << endl;

  return EXIT_SUCCESS;
}
