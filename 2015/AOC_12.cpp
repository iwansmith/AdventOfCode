#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include "CommonTools.h"


using namespace std;

int main()
{


  int sum = 0;


  for(string line; getline(cin,line);)
  {
    // Remove objects with Red
    for(string newline = ""; newline !=line;)
    {
      newline = line;

      string Depth = "";
      map<string, pair<int,int>> Braces;
      string RedDepth = "";

      for(auto c = line.begin(); c != line.end(); c++)
      {
        if ( *c == '{' or *c == '[')
        {
          Depth+=*c;
          Braces[Depth].first=c-line.begin();
        }

        if ( *c == '}' or *c == ']')
        {
          Braces[Depth].second=c-line.begin();
          Depth.erase(Depth.end()-1);
        }


        if ( string(c, c+3) == "red" && Depth.back() == '{')
         RedDepth = Depth;

        if ( Depth.size() < RedDepth.size() )
        {
          int a,b;
          tie(a,b) = Braces[RedDepth];
          line.erase(line.begin()+a, line.begin()+b+1);
          break;
        }
      }


    }

    auto end = line.begin();
    for(
        auto start = find_if(line.begin(), line.end(), [](char c){return (c >='0' and c <='9') or c == '-';});
        start != line.end();
        start = find_if(end, line.end(), [](char c){return (c >='0' and c <='9') or c == '-';})
        ){

        end = find_if(start+1, line.end(), [](char c){return not( c >='0' and c <='9');});

        sum += stoi(string(start, end));

    }


  }

  cout << sum << endl;

  return EXIT_SUCCESS;
}
