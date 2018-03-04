#include <iostream>
#include <cstdlib>

#include "CommonTools.h"
#include <algorithm>

using namespace std;

void increment(string& pword)
{

  for( auto c = pword.rbegin(); c !=pword.rend(); c++)
  {
    if( *c == 'z')
      *c = 'a';
    else
    {
      (*c)++;

      if ( *c == 'i' ) (*c)++;
      if ( *c == 'o' ) (*c)++;
      if ( *c == 'l' ) (*c)++;
      break;
    }

  }
}


bool IsValid(const string &pword)
{

  int nPair = 0;
  char lastPair = 0;

  for(int l = 1; l < pword.size();l++)
  {
    if ( pword[l] == pword[l-1] )
    {
      if ( pword[l] != lastPair )
        nPair++;

      lastPair = pword[l];

    }

  }

  int containsincrement = false;

  for(int l = 2; l < pword.size(); l++)
  {
      if ( pword[l] == pword[l-1]+1 and pword[l] == pword[l-2]+2 )
        containsincrement = true;
  }


  return containsincrement and nPair >1;
}

int main()
{

  string Password = "hxbxwxba";


  for( bool NotValid = true; NotValid;)
  {
    increment(Password);
    NotValid = not IsValid(Password);
  }
  cout << Password << endl;

  for( bool NotValid = true; NotValid;)
  {
    increment(Password);
    NotValid = not IsValid(Password);
  }
  cout << Password << endl;

  return EXIT_SUCCESS;
}
