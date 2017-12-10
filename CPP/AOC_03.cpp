#include <iostream>
#include <cstdlib>
#include <math.h>

#include <map>

inline int GetRadius( int location )
{
  if ( location == 0 )
    return 0;

  double sroot = pow((double)location-1, 0.5);

  return (sroot+1)/2;
}



int main(int ac, char *argv[])
{
  const int location = atoi(argv[1]);

  int radius = GetRadius(location);

  int s = location - pow(radius*2-1, 2) + radius;
  int StepsToMiddle = s % (radius*2);
  StepsToMiddle = std::min(StepsToMiddle, - (StepsToMiddle - 2*radius) );

  std::cout << radius + StepsToMiddle << std::endl;



  std::map<std::pair<int,int>, int> ValuesHeld;


  ValuesHeld[{0,0}] = 1;

  int X(1), Y(0);
  radius = 0;


  auto DoEvent = [&ValuesHeld](int X, int Y)
    {

      int EvVal =  \
        ValuesHeld[{X-1, Y-1 }] + \
        ValuesHeld[{X,   Y-1 }] + \
        ValuesHeld[{X+1, Y-1 }] + \
        ValuesHeld[{X-1, Y+1 }] + \
        ValuesHeld[{X,   Y+1 }] + \
        ValuesHeld[{X+1, Y+1 }] + \
        ValuesHeld[{X-1, Y   }] + \
        ValuesHeld[{X+1, Y   }];

      ValuesHeld[{X,Y}] = EvVal;

      std::cout << "X: " << X << " Y: " << Y << " Val: " << EvVal << std::endl;

      if ( EvVal > 312051 ) exit(0);

      return EvVal;
    };

  while ( true )
  {

    for(; Y <= radius; Y++)
      DoEvent(X,Y);

    for(; X >= -radius; X--)
      DoEvent(X,Y);

    for(; Y >= -radius; Y--)
      DoEvent(X,Y);

    for(; X <= radius+1; X++)
      DoEvent(X,Y);

    radius++;

  }






  return EXIT_SUCCESS;
}
