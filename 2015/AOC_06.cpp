#include <iostream>
#include <cstdlib>

#include "CommonTools.h"


using namespace std;

int main()
{

  int Lights[1000][1000] = {0};



  for(string line; getline(cin, line);)
  {

    vector<string> Commands;
    Commands = SplitString<string>(line);

    if ( Commands[0] == "turn")
    {
        int newVal = int(Commands[1] == "on")*2 -1;


      vector<int> Range_Low  = SplitString<int>(Commands[2], ",");
      vector<int> Range_High = SplitString<int>(Commands[4], ",");

      for( int X = Range_Low[0]; X <= Range_High[0]; X++)
        for( int Y = Range_Low[1]; Y <= Range_High[1]; Y++)
          Lights[X][Y] = max(Lights[X][Y] + newVal, 0);

    }

    else //( Commands[0] == "toggle")
    {


      vector<int> Range_Low  = SplitString<int>(Commands[1], ",");
      vector<int> Range_High = SplitString<int>(Commands[3], ",");

      for( int X = Range_Low[0]; X <= Range_High[0]; X++)
        for( int Y = Range_Low[1]; Y <= Range_High[1]; Y++)
          Lights[X][Y] += 2;

    }
  }

  int nOn = 0;

  for( int X = 0; X < 1000; X++)
    for( int Y = 0; Y < 1000; Y++)
      nOn += Lights[X][Y];

  cout << nOn << endl;



  return EXIT_SUCCESS;
}
