#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{

  std::string number;
  std::vector<int> Jumps;



  while(getline(std::cin, number))
  {

    Jumps.push_back(atoi(number.c_str()));
  }

  int counter = 0;
  int Position = 0;


  const int jumpsSize = Jumps.size();
  while ( Position < jumpsSize and Position >= 0 )
  {

      int &j = Jumps[Position];
      int j2 = j;
      j >=3 ? j-- : j++;

      Position += j2;
      counter++;


  }

  std::cout << counter << std::endl;
  return EXIT_SUCCESS;
}
