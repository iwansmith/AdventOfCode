#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"


using namespace std;

map<string,map<string,int>> Scores;


int GetScore(vector<string>& Ordering)
{
  int Score = 0;

  for(auto it = Ordering.begin(); it != Ordering.end()-1; it++)
  {
      Score += Scores[*it][*(it+1)];
      Score += Scores[*(it+1)][*it];
  }

  Score += Scores[Ordering[0]][Ordering.back()];
  Score += Scores[Ordering.back()][Ordering[0]];

  return Score;

}

int factorial(int n)
{
  if ( n == 1) return 1;
  return factorial(n-1)*n;
}

int main()
{


  vector<string> Ordering;

  for(string line; getline(cin, line);)
  {
    vector<string> Words = SplitString<string>(line);

    string& P1 = Words[0];
    string& P2 = Words.back();

    P2.erase(P2.end()-1);

    Scores[P1][P2] = ( Words[2] == "gain" ? 1 : -1) * stoi(Words[3]);

    if (count(Ordering.begin(), Ordering.end(), P1) == 0 )
      Ordering.push_back(P1);
    if (count(Ordering.begin(), Ordering.end(), P2) == 0 )
      Ordering.push_back(P2);

  }

  for(auto& p:Ordering)
  {
   Scores[p]["me"] = 0;
   Scores["me"][p] = 0;
  }

  Ordering.push_back("me");

  int maxScore = -999999;

  const int nPerm = factorial(Ordering.size());

  for( int n = 0; n < nPerm; n++)
  {
    maxScore = max(maxScore, GetScore(Ordering));
    next_permutation(Ordering.begin(), Ordering.end());
  }

  cout << maxScore << endl;
  return EXIT_SUCCESS;
}
