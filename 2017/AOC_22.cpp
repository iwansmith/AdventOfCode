#include <iostream>
#include <cstdlib>
#include <deque>
#include <utility>

using namespace std;


template<typename T>
ostream& operator << (ostream& lhs, deque<T>& rhs)
{

  for( auto& r: rhs)
    lhs << r << endl;

  return lhs;

}


int main()
{

  deque<string> NodeMap;


  for( string line; getline(cin, line); )
    NodeMap.push_back(move(line));

  int MapSize_Y = NodeMap.size();
  int MapSize_X = NodeMap[0].size();

  int X = NodeMap[0].size()/2;
  int Y = NodeMap.size()/2;

  int Dir_X = 0;
  int Dir_Y = -1;


  int BecameInfected = 0;
  const int nStep = 10000000;

  for( int step =0 ; step < nStep       ; step++)
  {

    if ( X< 0)
    {
        MapSize_X++;
        for(auto& m: NodeMap)
            m.insert(m.begin(), '.');
        X++;
    }
    if ( Y < 0 )
    {
        MapSize_Y++;
        NodeMap.push_front(string(MapSize_X, '.'));
        Y++;
    }

    if  ( X >= MapSize_X )
    {
      MapSize_X++;
      for(auto& m: NodeMap)
          m += ".";
    }
    if  ( Y >= MapSize_Y )
    {
      MapSize_Y++;
      NodeMap.push_back(string(MapSize_X, '.'));
    }

    char& node = NodeMap[Y][X];

    for( int i = 0; i < MapSize_Y+1; i++)
      cout << "\x1b[A";
    cout << NodeMap << endl;


    if ( node == '#'){
      // Turn Right
      int tmp = Dir_Y;
      Dir_Y = Dir_X;
      Dir_X = - tmp;

      node = 'F';
    }
    else if ( node == '.'){
      // Turn Left
      int tmp = Dir_X;
      Dir_X = Dir_Y;
      Dir_Y = - tmp;

      node = 'W';
    }
    else if ( node == 'W'){

      BecameInfected++;
      node = '#';
    }
    else if ( node == 'F'){
      Dir_X = -Dir_X;
      Dir_Y = -Dir_Y;

      node = '.';
    }


    X += Dir_X;
    Y += Dir_Y;

  }

  cerr << BecameInfected << endl;


  return EXIT_SUCCESS;
}
