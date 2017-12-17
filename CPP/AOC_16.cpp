#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

void DoPermutation( vector<char>& programs, vector<string>& CommandList )
{

  for(auto command: CommandList)
  {
      char c = command[0];
      command.erase(0, 1);

      if ( c == 's')
      {
        rotate(programs.begin(), programs.end()-atoi(command.c_str()), programs.end()) ;
        continue;
      }

      string s_n1( command.begin(), find(command.begin(), command.end(), '/'));
      string s_n2( find(command.begin(), command.end(), '/')+1, command.end());


      if ( c == 'x')
      {
        int n1 = atoi(s_n1.c_str());
        int n2 = atoi(s_n2.c_str());
        swap(programs[n1], programs[n2]);
      }
      else if ( c == 'p')
      {
          char n1 = *s_n1.data();
          char n2 = *s_n2.data();
          swap( *find( programs.begin(), programs.end(), n1), *find( programs.begin(), programs.end(), n2));
      }
  }


}



int main()
{


  string commands = "s1,x3/4,pe/b"; getline(cin, commands);

  for(
      int comloc = commands.find(',');
      comloc < commands.size();
      comloc = commands.find(','), comloc)
    {
      commands.replace(comloc, 1, " ");
    }


  vector<char> programs(16);
  iota(programs.begin(), programs.end(), 'a');
  vector<string> commandList;

  istringstream ss(commands);
  for( string command; ss >> command; )
  {
      commandList.push_back(command);
  }


  string Ps = programs.data();
  Ps = string(Ps.begin(), Ps.begin()+16);

  int count = 0;
  for( string Ps2 = "" ; Ps != Ps2 ;count++)
  {
    DoPermutation(programs, commandList);

    Ps2 = programs.data();
    Ps2 = string(Ps2.begin(), Ps2.begin()+16);


  }


  const int nRemain =(int)1e9 % count;

  for ( int i = 0; i < nRemain; i++)
    DoPermutation(programs, commandList);


  for ( char c: programs)
    cout << c;
  cout << endl;


  return EXIT_SUCCESS;
}
