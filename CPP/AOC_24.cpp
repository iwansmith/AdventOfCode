#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename FIRST, typename SECOND>
ostream& operator<<(ostream& lhs, pair<FIRST,SECOND> rhs)
{
  lhs << rhs.first << "  " << rhs.second;
  return lhs;
}


pair<int, int> AddBridge( int score, int nProng, int length, vector<pair<int,int>>& Bridges)
{

  pair<int,int> maxscore{score, length};

  auto Find_L = [nProng](pair<int,int> B){ return B.first==nProng or B.second == nProng;};

  for(  auto p = find_if(Bridges.begin(), Bridges.end(), Find_L);
        p < Bridges.end();
        p = find_if(p+1, Bridges.end(), Find_L)
      ){

      int p1 = p -> first;
      int p2 = p -> second;

      if ( p2 == nProng )
        swap(p1, p2);

      const int loc = p - Bridges.begin();
      vector<pair<int, int>> Bridges2 = Bridges;

      Bridges2.erase( Bridges2.begin()+ loc );



      maxscore = max( maxscore, AddBridge( score + p1 + p2, p2, length+1, Bridges2 ),
        [](pair<int,int> lhs, pair<int,int> rhs)
        {
          if ( lhs.second > rhs.second )
            return false;
          if ( lhs.second == rhs.second && lhs.first > rhs.first)
            return false;
          return true;
        });

  }


  return maxscore;

}

int main()
{


  vector<pair<int,int>> Bridges;

  for( string line; getline(cin, line);)
  {
      size_t loc;
      int lhs = stoi(line, &loc);
      line.erase(0, loc+1);
      int rhs = stoi(line);

      Bridges.push_back({lhs, rhs});

  }


  cout << AddBridge(0, 0, 0, Bridges) << endl;



  return EXIT_SUCCESS;
}
