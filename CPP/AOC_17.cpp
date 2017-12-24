#include <iostream>
#include <cstdlib>

#include <deque>
#include <algorithm>

using namespace std;

int main()
{

  int Input = 394;


  // Part 1
  deque<int> Stack{0};
  int location = 0;
  for ( int count = 1; count <= 2017; count++)
  {

    location += Input;
    location %= count;
    location += 1;

    Stack.insert(Stack.begin()+location, 1, count) ;

  }

  cout << *(find(Stack.begin(), Stack.end(), 2017)+1) << endl;

  // Part 2
  location = 0;
  int After0 = 0;
  for ( int count = 1; count <= 50e6; count++)
  {

    location = ( location + Input ) % count + 1; // using r-values brings time down by 25% // or just use -O1

    if (location == 1)
      After0 =  count;
  }


  cout << After0 << endl;



  return EXIT_SUCCESS;
}
