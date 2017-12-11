#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int main()
{


  std::string line;
  getline(std::cin, line);
  std::istringstream is(line);


  int Bank;
  std::vector<int> Banks;
  while( is >> Bank)
    Banks.push_back(Bank);

  std::unordered_map<std::string, int> SetOfBanks;
  int counter = 0;
  while ( true )
  {


    std::string Hashable;
    for(auto i: Banks)
    {
      Hashable += char( i );
    }

    if ( SetOfBanks[Hashable] != 0 )
      {
        std::cout << "Collision Found! Iteration Number " << counter << " Loop Size: "<< counter - SetOfBanks[Hashable] << std::endl;
        std::exit(0);
      }
    else
      SetOfBanks[Hashable] = counter;

    auto maxelement = std::max_element(Banks.begin(), Banks.end());

    const int BankContains = *maxelement;
    *maxelement = 0;

    for(int i = 0; i < BankContains; i++)
    {

      maxelement++;
      if ( maxelement == Banks.end() )
        maxelement = Banks.begin();

      (*maxelement)++;
    }

    counter++;

  }



  return EXIT_SUCCESS;
}

