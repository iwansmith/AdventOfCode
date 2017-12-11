#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>

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

    double t_X = X>0 ? X : -X;
    double t_Y = Y>0 ? Y : -Y;

    int nSteps = 0;
    nSteps += 2*t_X;
    t_Y -= t_X;
    if ( t_Y<0 ) t_Y = -t_Y;
    nSteps += t_Y;

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