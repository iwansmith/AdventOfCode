#include <iostream>
#include <cstdlib>

#include "CommonTools.h"


using namespace std;

int main()
{

  vector<string> Lights;
  cin >> Lights;


  const int Nx = Lights[0].size();
  const int Ny = Lights   .size();

  for(auto& L: Lights)
  {
      L.insert(L.begin(), '.');
      L.insert(L.end(),   '.');
  }

  Lights.insert(Lights.begin(), string(Nx+2, '.'));
  Lights.insert(Lights.end()  , string(Nx+2, '.'));

  Lights[1]  [1]   = '#';
  Lights[1]  [100] = '#';
  Lights[100][1]   = '#';
  Lights[100][100] = '#';

  for( int i = 0; i < 100; ++i)
  {

      for(auto&L:Lights)
        cout << L << endl;

      vector<string> NextLights = Lights;

      for( int x = 1; x <= Nx; x++ )
      {
          for( int y = 1; y <= Ny; y++ )
          {
              int nNeighbour = - int(Lights[x][y] == '#');


              for( int dx = -1; dx <= 1; dx++)
                for( int dy = -1; dy <= 1; dy++)
                  nNeighbour += int(Lights[x+dx][y+dy] == '#');


              if ( Lights[x][y] == '#' and nNeighbour/2 != 1)
                NextLights[x][y] = '.';

              if ( Lights[x][y] == '.' and nNeighbour == 3)
                NextLights[x][y] = '#';

          }
      }

      Lights = move(NextLights);
      Lights[1]  [1]   = '#';
      Lights[1]  [100] = '#';
      Lights[100][1]   = '#';
      Lights[100][100] = '#';

      int nOn = 0;
      for( int x = 1; x <= Nx; x++ )
      {
          for( int y = 1; y <= Ny; y++ )
          {
              nOn += int(Lights[x][y] == '#');
          }
      }
      cout << nOn << endl;

  }


  return EXIT_SUCCESS;
}
