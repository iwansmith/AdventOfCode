#include <iostream>
#include <algorithm>

using namespace std;

string NextNumber(string S)
{

  string NewNumber;
  NewNumber.reserve(S.size()*2);

  for (auto loc = S.begin(); loc < S.end(); )
  {
    int len = find_if(loc, S.end(), [&loc](char c){ return c != *loc; }) - loc;


    NewNumber += len + '0';
    NewNumber += *loc;

    loc += len;

  }

  return NewNumber;
}



int main()
{

  string Input = "3113322113";
  for(int rep = 0; rep < 50; rep++)
    Input = NextNumber(Input);

  cout << Input.size() << endl;

  return EXIT_SUCCESS;
}
