#ifndef SPECIALCOUT
#define SPECIALCOUT

#include <iostream>

#include <vector>
#include <map>
#include <set>

using namespace std;

template<typename _iterator>
void __OutputContainer(ostream& stream, const _iterator& Begin, const _iterator& End)
{

  for(_iterator it = Begin; it != End; it++)
    stream << *it << "  ";

}

template<typename _iterator>
void __OutputAssociativeContainer(ostream& stream, const _iterator& Begin, const _iterator& End)
{
  for(_iterator it = Begin; it != End; it++)
    stream << it->first << ": " << it->second << endl;

}



template<typename T>
ostream& operator <<( ostream& lhs, vector<T> rhs)
{

  __OutputContainer(lhs, rhs.begin(), rhs.end());
  return lhs;
}

template<typename T>
ostream& operator <<( ostream& lhs, set<T> rhs)
{

  __OutputContainer(lhs, rhs.begin(), rhs.end());
  return lhs;
}


template<typename T1, typename T2>
ostream& operator <<( ostream& lhs, map<T1, T2> rhs)
{
  __OutputAssociativeContainer(lhs, rhs.begin(), rhs.end());
  return lhs;
}


#endif
