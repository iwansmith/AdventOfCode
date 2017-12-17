#include <iostream>
#include <cstdlib>

#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  int Input = 394;


  // Part 1
  deque<int> Stack{0};
  int location = 0;
  for ( int count = 0; count < 2017; count++)
  {
    int size = count+1;

    location += Input;
    location %= size;
    location +=1;

    Stack.insert(Stack.begin()+location, 1, size);

  }

  cout << *(find(Stack.begin(), Stack.end(), 2017)+1) << endl;

  // Part 2
  location = 0;
  int After0 = 0;
  for ( int count = 0; count < 50e6; count++)
  {

    location += Input;
    location %= (count+1);
    location +=1;

    if (location == 1)
      After0 =  count+1;
  }


  cout << After0 << endl;



  return EXIT_SUCCESS;
}
