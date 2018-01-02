#ifndef SPLITSTRING
#define SPLITSTRING


#include <sstream>
#include <vector>

using namespace std;


template<typename T>
vector<T> SplitString(const string& Input, const string& separator = " ")
{
  vector<T> Output;

  unsigned int LastLocation = 0;
  for( unsigned int location = Input.find(separator);
       LastLocation < Input.size();
       location = Input.find(separator, LastLocation) )
   {
      if (location > Input.size() )
        location = Input.size();

     istringstream iss( string(Input.begin()+ LastLocation, Input.begin()+location));
     T TemporaryValue;

     iss >> TemporaryValue;
     Output.push_back(TemporaryValue);

     LastLocation = location + separator.size();
   }

  return Output;

};

#endif
