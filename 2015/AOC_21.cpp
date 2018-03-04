#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"


bool PlayGame(vector<int> Player, vector<int> Boss)
{

  while ( true )
  {
    // Player attacks Boss
    {
      int damage = max(Player[1] - Boss[2], 1);
      Boss[0] -= damage;

      if ( Boss[0] <= 0 ) return true;
    }

    // Boss attacks player
    {
      int damage = max(Boss[1] - Player[2], 1);
      Player[0] -= damage;

      if ( Player[0] <= 0 ) return false;
    }

  }
  return true;

}



using namespace std;

int main()
{

  const vector<vector<int>> Weapons
  {
    { 8,     4,       0},
    {10,     5,       0},
    {25,     6,       0},
    {40,     7,       0},
    {74,     8,       0},
  };

  const vector<vector<int>> Armor
  {
    {  0,     0,       0},
    { 13,     0,       1},
    { 31,     0,       2},
    { 53,     0,       3},
    { 75,     0,       4},
    {102,     0,       5},
  };

  const vector<vector<int>> Rings
  {
    {  0,     0,       0},
    {  0,     0,       0},
    { 25,     1,       0},
    { 50,     2,       0},
    {100,     3,       0},
    { 20,     0,       1},
    { 40,     0,       2},
    { 80,     0,       3},
  };


  const vector<int> Boss = {109, 8, 2};


  int MaxCost = 0;
  for(const auto& W: Weapons)
  {
    for(const auto& A: Armor)
    {
      for(auto R1 = Rings.begin(); R1 < Rings.end()-1; R1++)
      {
        for(auto R2 = R1+1; R2 < Rings.end(); R2++)
        {
            vector<int> Player(3,0);
            Player[0] = 100;
            Player[1] = W[1] + (*R1)[1] + (*R2)[1];
            Player[2] = A[2] + (*R1)[2] + (*R2)[2];

            int Cost = W[0] + A[0] + (*R1)[0] + (*R2)[0];

            if ( not PlayGame(Player, Boss) )
              MaxCost = max(MaxCost, Cost);

        }
      }
    }
  }

  cout << MaxCost << endl;
  return EXIT_SUCCESS;
}
