#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

#include <deque>
#include <thread>
#include <mutex>
#include <chrono>
#include <cmath>

using namespace std;
int Try1()
{

  /* What do the varibles do:
   *
   * Plain translated code
   *
   * a - Flag
   * b - counter
   * c - Upper Limit fixed variable?
   * d - Counter 2 -> ...
   * e - Counter 2 -> ...
   * f - Flag
   * g - Unknown
   *
   */


  int a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0);

  b = 57;
  c = b;
  if ( a != 0 )
  {
   b *= 100;
   b += 100000;
   c = b;
   c += 17000;
  }

  do
  {
    f = 1;
    d = 2;
    do
    {
      e = 2;
      do
      {
        g = d;

        g *= e;
        g -= b;
        if ( g == 0 )
          f = 0;

        e++;
        g = e;
        g -=b;
      }while( g != 0 );

      d++;
      g = d;
      g -= b;
    }while( g != 0 );

    if ( f == 0 )
      h++;

    g = b;
    g -= c;

    if ( g == 0 )
      return EXIT_SUCCESS;
    b += 17;
  }while(true);



  return EXIT_SUCCESS;
}

int Try2()
{

  // Scope variables

  int a(0), b(0), c(0), g(0), h(0);

  b = 57;
  c = b;
  if ( a != 0 )
  {
   b *= 100;
   b += 100000;
   c = b;
   c += 17000;
  }

  do
  {
    int f = 1;
    int d = 2;
    do
    {
      int e = 2;
      do
      {
        g = d;

        g *= e;
        g -= b;
        if ( g == 0 )
          f = 0;
          // if b == d*e // i.e. if b is not a prime number

        e++;
        g = e;
        g -= b;
        // Keep iterating e until it reaches b
      }while( g != 0 );

      d++;
      g = d;
      g -= b;
      // Keep iterating d until it reaches b
    }while( g != 0 );

    if ( f == 0 )
      h++;

    g = b;
    g -= c;

    if ( g == 0 )
      return h;

    b += 17;
  }while(true);


  return 0;
}

bool isPrime( int p ){

  if ( (p/2)*2 == p ) return false;
  const int rootp = sqrt(p);

  for( int i = 3; i <= rootp; i+=2)
    if ( (p/i)*i == p ) return false;

  return true;

}

int main(){

  int h = 0;
  for( int b = 57*100 + 100000; b <= 57*100 + 100000+ 17000; b+= 17 )
  {
    if ( not isPrime(b) )
      h++;
  }

  cout << h << endl;


};
