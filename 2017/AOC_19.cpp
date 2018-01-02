#include <iostream>
#include <cstdlib>

#include <vector>

using namespace std;



ostream& operator<<( ostream& lhs, vector<string> rhs)
{

  for (auto& l:rhs)
    lhs << l << endl;

  return lhs;

}




int main()
{

  vector<string> lines;
  for( string line; getline(cin, line); )
    lines.push_back(" " + line + " " );

  int X(0), Y(0);

  X = lines[0].find("|");

  string LettersFound = "";

  int increment = 1;
  int direction = 0;

  int steps = 0;

  while ( true )
  {

    steps++;

    if ( lines[Y][X] == '+' )
    {
      direction ^= 1;

      if ( direction == 0 )
      {
        if ( lines[Y-1][X] == ' ' or lines[Y+1][X] == '|' )
          increment = 1;
        else
          increment = -1;
      }
      if ( direction == 1 )
      {
        if ( lines[Y][X-1] == ' ' or lines[Y][X+1] == '-' )
          increment = 1;
        else
          increment = -1;
      }

    }

    //auto newLines = lines;
    //newLines[Y][X] = '#';
    //cout << newLines << endl;


    if ( direction == 0 )
      Y += increment;
    if ( direction == 1 )
      X += increment;

    char c = lines[Y][X];

    if ( c >= 'A' && c <= 'Z')
      LettersFound += c;

    if ( c == ' ' )
      break;

  }

  cout << LettersFound << endl;
  cout << steps << endl;

  return EXIT_SUCCESS;
}
