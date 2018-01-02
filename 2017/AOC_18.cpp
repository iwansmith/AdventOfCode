#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

#include <deque>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& lhs, const map<T1, T2>& rhs)
{

  for( auto& R: rhs )
    lhs << R.first << "  " << R.second << "  ";

  return lhs;

}


bool isNumber(string teststring)
{

  if (teststring.size() == 1)
    if ( teststring[0] >= 'a' && teststring[0] <= 'z' )
      return false;
  if (teststring.size() == 0)
    return false;


  return true;
}

int main()
{


  vector<string> Commands;
  for( string line; getline( cin, line);)
    Commands.push_back(line);


  vector<deque<int>> Send {{},{}};
  vector<int> Stuck {{0}, {0}};
  mutex Send_mutex;


  auto RunSystem = [&Commands, &Send, &Send_mutex, &Stuck](int p)
  {
    map<string, long long int> Register;
    Register["p"] = p;

    int Sent = 0;
    for ( auto it = Commands.begin(); it < Commands.end(); it++)
    {

      if ( it < Commands.begin())
        return 0;

      //cout << Register << endl;

      istringstream iss( (string)*it );
      string command;  iss >> command;
      string X;        iss >> X;
      string Y;        iss >> Y;



      long long int i_X(0), i_Y(0);
      if ( isNumber(Y))
        i_Y = stoi(Y);
      else if ( Y.size() > 0)
        i_Y = Register[Y];

      if     ( command == "set" )
        Register[X] = i_Y;

      else if( command == "add" )
        Register[X] += i_Y;

      else if( command == "mul" )
        Register[X] *= i_Y;

      else if( command == "mod" )
        if ( i_Y != 0 )
          Register[X] %= i_Y;




      if ( isNumber(X))
        i_X = stoi(X);
      else
        i_X = Register[X];



      if( command == "snd")
      {
        lock_guard<mutex> guard(Send_mutex);
        Send[p].push_back( i_X );
        Sent++;
        cout << "Sent " << "  " << p << "  " << Sent << endl;
      }

      if( command == "rcv")
      {

        while ( Send[1-p].empty() )
        {
          Stuck[p] = 1;
          if ( Stuck[p-1] == 1)
            return 0;

          this_thread::sleep_for(chrono::milliseconds(1));
        }
        Stuck[p] = 0;
        lock_guard<mutex> guard(Send_mutex);
        Register[X] = Send[1-p][0];
        Send[1-p].pop_front();

      }



      if( command == "jgz" )
        if ( i_X > 0 )
          it += i_Y-1;

      //cout << command << "  " << reg << "  " << i_val << endl;
    }
    return 0;
  };


  thread t1( RunSystem, 0);
  thread t2( RunSystem, 1);

  t1.join();
  t2.join();


  return EXIT_SUCCESS;
}
