#include <iostream>
#include <cstdlib>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{

  long int next_A = 512;
  long int next_B = 191;


  int count = 0;

  for ( int i = 0; i < 5e6; i++)
  {
      do{
          next_A = ( 16807 * next_A ) % 2147483647;
      }while( next_A % 4 != 0 );

      do{
        next_B = ( 48271 * next_B ) % 2147483647;
      }while ( next_B % 8 != 0 );

      stringstream iss_A;
      stringstream iss_B;

      iss_A << bitset<16>(next_A);
      iss_B << bitset<16>(next_B);

      if ( iss_A.str() == iss_B.str() )
        count++;



  }

  cout << count << endl;
  return EXIT_SUCCESS;
}
