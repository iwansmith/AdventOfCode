#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{

  map<string, int> Register;
  vector<string> Instructions;

  auto IsValid = [&Register, &Instructions]()
  {
    string operation = Instructions[5];

    int l = Register[Instructions[4]];
    int r = atoi(Instructions[6].c_str());

    if ( operation == ">" )  return l >  r;
    if ( operation == ">=" ) return l >= r;
    if ( operation == "<" )  return l <  r;
    if ( operation == "<=" ) return l <= r;
    if ( operation == "==" ) return l == r;
    if ( operation == "!=" ) return l != r;

    std::cout << "Fuck: " << operation << std::endl;

    return false;
  };

  auto DoOperation = [&Register, &Instructions]()
  {

    string operation = Instructions[1];

    int& Bank = Register[Instructions[0]];
    int Delta = atoi( Instructions[2].c_str() );

    if      ( operation == "inc" ) Bank += Delta;
    else if ( operation == "dec" ) Bank -= Delta;


  };

  int BiggestEver = 0;

  auto GetMax = [](auto Register)
  {
    return max_element(Register.begin(), Register.end(), [](auto &lhs, auto &rhs)
    {
      return lhs.second < rhs.second;
    })->second;
  };

  string Instruction;
  while ( getline(std::cin, Instruction))
  {
    {
      Instructions.clear();
      istringstream is(Instruction);
      std::string inst;
      while ( is >> inst )
        Instructions.push_back(inst);
    }

    if (not IsValid())
      continue;
    DoOperation();

    int max_it = GetMax(Register);
    BiggestEver = max(BiggestEver, max_it);
  }

  int max_it = GetMax(Register);



  std::cout << max_it << "  " << BiggestEver << std::endl;


  return EXIT_SUCCESS;
}
