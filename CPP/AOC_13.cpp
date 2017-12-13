#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
using namespace std;

int main()
{

  map<int,int> depthrange;

  int severity = 0;
  for( string line; getline(cin,line); )
  {

    line.erase(line.find(':'), 1);
    istringstream iss(line);

    int depth; iss >> depth;
    int range; iss >> range;

    bool Found = depth%((range-1)*2) == 0;

    if ( Found ) severity += depth*range;

    depthrange[depth] = range;

  }

  cout << severity << endl;

//Part 2


  for (int offset = 0; ; offset++)
  {
    bool Caught = false;
    for ( auto &DR: depthrange )
    {
        int depth = DR.first;
        int range = DR.second;

        Caught = (depth+offset)%((range-1)*2) == 0;
        if ( Caught )
          break;
    }
    if ( not Caught )
    {
      cout << offset << endl;
      exit(0);
    }


  }

  return EXIT_SUCCESS;
}
