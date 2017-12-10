#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

int main()
{

  int CHK(0), CHK2(0);
  std::string line;
  while ( getline( std::cin, line ) ) {

     std::istringstream is( line );
     std::vector<int> v_line;
     int i(0), high(0), low(9999999);
     while ( is >> i )
     {
         std::cout << i << "  ";
         if ( i > high )
           high = i;
         if ( i < low )
           low = i;

         v_line.push_back(i);
     }

     std::cout << "  :  " << low << "  " << high << "  " << high-low << "  " << std::endl;
     CHK += high-low;

     std::sort(v_line.begin(), v_line.end());

     for ( auto l = v_line.begin(); l < v_line.end(); l++)
     {
         for ( auto h = l+1; h < v_line.end(); h++)
         {
             if ( (*h / *l) * *l == *h )
             {
               CHK2 += *h / *l;
               break;
             }
         }
     }


  }


  std::cout << CHK << std::endl;
  std::cout << CHK2 << std::endl;


  return EXIT_SUCCESS;
}
