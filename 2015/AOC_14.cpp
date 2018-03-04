#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "CommonTools.h"


using namespace std;


struct Reindeer
{

  string name;
  int    speed;
  int    FlyTime;
  int    RestTime;

  int Score = 0;

  int GetDistance(int time)
  {

    int TotTime = FlyTime + RestTime;
    int nCycle = time / TotTime;

    int Dist = nCycle * FlyTime * speed;

    int tRemain = time - nCycle * TotTime;

    if ( tRemain < FlyTime )
      Dist += tRemain * speed;
    else
      Dist += FlyTime * speed;

    return Dist;
  };

};


int main()
{

  vector<Reindeer> Rs;

  for( string line; getline(cin, line); )
  {

      vector<string> input = SplitString<string>(line);

      Reindeer R;
      R.name    = input[0];
      R.speed   = stoi(input[3]);
      R.FlyTime = stoi(input[6]);
      R.RestTime= stoi(input[13]);

      Rs.push_back(R);
  }


  for(int i = 1; i <= 2503; i++ )
  {
    auto Furthest = max_element(Rs.begin(), Rs.end(), [i](Reindeer& lhs, Reindeer& rhs)
                                {
                                  return lhs.GetDistance(i) < rhs.GetDistance(i);
                                });

    Furthest->Score++;
  }

  auto HighestScore = max_element(Rs.begin(), Rs.end(), [](const Reindeer& lhs, const Reindeer& rhs)
                              {
                                return lhs.Score < rhs.Score;
                              });


  cout << HighestScore->Score << endl;


  return EXIT_SUCCESS;
}
