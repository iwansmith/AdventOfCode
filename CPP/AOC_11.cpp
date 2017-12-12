#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

struct location
{
  double X;
  double Y;

  const location& operator+= (location rhs)
  {
    X += rhs.X;
    Y += rhs.Y;
    return *this;
  };

  int StepsAway()
  {

    double t_X = abs(X);
    double t_Y = abs(Y);

    int nSteps = 2*t_X;

    t_Y -= min( t_Y, t_X );

    nSteps += abs(t_Y);
    return nSteps;

  }
};


int main()
{
  string path;
  getline(cin,path);


  location CurrentLocation{0,0};
  int FurthestStepsAway = 0;

  auto lhs = path.begin()-1;
  while ( lhs != path.end() )
  {
      auto rhs = find(lhs+1, path.end(), ',');

      string direction(lhs+1, rhs);
      lhs = rhs;

           if ( direction == "n"  ) CurrentLocation += {  0.0,  1.0};
      else if ( direction == "ne" ) CurrentLocation += {  0.5,  0.5};
      else if ( direction == "se" ) CurrentLocation += {  0.5, -0.5};
      else if ( direction == "s"  ) CurrentLocation += {  0.0, -1.0};
      else if ( direction == "sw" ) CurrentLocation += { -0.5, -0.5};
      else if ( direction == "nw" ) CurrentLocation += { -0.5,  0.5};

      FurthestStepsAway = max( CurrentLocation.StepsAway(), FurthestStepsAway);

  }

  // Location can be rotated without losing generality

  cout << CurrentLocation.StepsAway() << "  " << FurthestStepsAway << endl;


  return EXIT_SUCCESS;
}
