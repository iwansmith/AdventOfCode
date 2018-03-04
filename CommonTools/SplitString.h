#ifndef SPLITSTRING
#define SPLITSTRING


#include <sstream>
#include <vector>

using namespace std;


template<typename T>
istream& operator >>(istream& lhs, vector<T>& rhs)
{

  T TemporaryValue;
  while (lhs >> TemporaryValue)
    rhs.push_back(TemporaryValue);

  return lhs;
}



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

     string ShortString(Input.begin()+ LastLocation, Input.begin()+location);

     LastLocation = location + separator.size();


     if( ShortString == separator || ShortString.empty() )
       continue;

     istringstream iss( ShortString );
     T TemporaryValue;

     iss >> TemporaryValue;
     Output.push_back(TemporaryValue);

   }

  return Output;

};

#endif

