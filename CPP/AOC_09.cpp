#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  string Instruction;
  int DeletedGarbage = 0;
  while ( getline(cin, Instruction))
  {
    int loc;

    while( (loc = Instruction.find('!')) < Instruction.size() )
    {
      Instruction.erase(loc, 2);
    }

    while( (loc = Instruction.find('<')) < Instruction.size() )
    {
        int loc2 = Instruction.find('>');
        Instruction.erase(loc, loc2-loc+1);
        DeletedGarbage += loc2-loc-1;
    }

    int score = 0;
    int sumscore = 0;
    for (auto c: Instruction )
    {
        if ( c == '{' ) score++;
        if ( c == '}' ) sumscore+=score, score--;
    }
    cout << sumscore << "  " << DeletedGarbage << endl;
  }

  return EXIT_SUCCESS;
}
